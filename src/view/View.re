module Vdom = Virtual_dom.Vdom;

/*
 * A square can be modified only if it is unmarked and active
 */
let view_of_square =
    (
      ~inject: Update.Action.t => Vdom.Event.t,
      ~is_active: bool,
      ~index: Grid.index,
      square: Model.square,
    )
    : Vdom.Node.t =>
  switch (square) {
  | Unmarked =>
    let click_handlers =
      is_active
        ? [
          Vdom.Attr.on_click(_ => inject(Update.Action.MarkSquare(index))),
        ]
        : [];
    Vdom.Node.div([Vdom.Attr.classes(["square"]), ...click_handlers], []);
  | Marked(p) =>
    Vdom.Node.div([Vdom.Attr.classes(["square"])], [PlayerMark.view(p)])
  };

/*
 * To dram a grid, we need to draw the lines, squares, and the winner line (if win)
 * lines can be drawn by GridLines.view
 */
let view_of_grid =
    (~inject: Update.Action.t => Vdom.Event.t, grid: Model.grid): Vdom.Node.t => {
  let squares =
    Grid.index_list
    |> List.map(index => {
         let square = grid |> Grid.get_item(index);
         let is_active =
           switch (Model.winner(grid)) {
           | Some(_) => false
           | None => true 
           };
         view_of_square(~inject, ~is_active, ~index, square);
       });
  let winner_line =
    Model.winner(grid)
    |> Option.map(((_, three_in_a_row)) => WinnerLine.view(three_in_a_row))
    |> Option.to_list;
  Vdom.Node.div(
    [Vdom.Attr.classes(["grid"])],
    [GridLines.view] @ squares @ winner_line,
  );
};

/*
 * TODO1: build a "view of subgrid":
 * Input: inject, is_active, index, the subgrid to draw
 * Steps: 1. update square similar as original version
 *        2. judge winner line for subgrid:
 *            if the player has won the subgrid, the subgrid will be marked with the winner
 *            PlayerMark.view: Play.t => Vdom.Node.t can be used to draw the subgrid
 * Output: a div with class ["subgrid", "active" or "inactive"], 
 *         containing gridlines, squares and winner line
 */

/*
 * TODO2: build a "view of grid":
 * Input: inject, active_subgrid: option(Grid.index), grid
 * Steps: 1. fetch the subgrid
          2. check whether the subgrid is active: 
             when there is (i) no subgrid winner
             and (ii) match the active_subgrid
          3. use view_of_subgrid to draw the Node
 *        4. generate the winner line and build the output Node similar as original version
 * Output: Same as the original view_of_grid
 */


/* Note: the additional parameter active_subgrid is recorded in the model */
let view = (~inject, model: Model.t) => {
  let cursor_attr =
    Vdom.Attr.create(
      "style",
      switch (model.player_turn) {
      | X => "cursor: url(cursor-x.svg), pointer;"
      | O => "cursor: url(cursor-o.svg), pointer;"
      },
    );
  Vdom.Node.div(
    [Vdom.Attr.id("board"), cursor_attr],
    [view_of_grid(~inject, model.board)],
  );
};

/*
 * current structure:
 * <div id="board">
  *   <div class="grid">
  *     <div class="grid-lines">...</div>
  *     <div class="square">...</div>
  *     ...
  *     <div class="square">...</div>
  *     (<div class="winner-line">...</div>)
  *   </div>
  * </div>
 */

 /*
  * expected structure:
  * <div id="board">
  *   <div class="grid">
  *     <div class="grid-lines">...</div>
  *     <div class="inactive subgrid">
  *       <div class="grid-lines">...</div>
  *       <div class="square">...</div>
  *       ...
  *       <div class="square">...</div>
  *       (<div class="winner-line">...</div>
  *       <div class="player-mark">...</div>)
  *     </div>
  *     <div class="subgrid active">...</div>
  *     ...
  *     <div class="inactive subgrid">...</div>
  *     <div class="winner-line">...</div>
  *   </div>
  * </div>
  */