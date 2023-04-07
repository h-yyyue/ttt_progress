module Action = {
  [@deriving sexp]
  type t =
    | MarkSquare(Grid.index);
};

let update = (action: Action.t, model: Model.t): Model.t =>
  switch (action) {
  | MarkSquare(index) =>
    let new_grid =
      model.board |> Grid.put_item(index, Model.Marked(model.player_turn));
    let next_turn = Player.toggle(model.player_turn);
    {board: new_grid, player_turn: next_turn};
  };

/*
 * Design the new update!
 * 1. Update the board
 *    fetch the modified subgrid
 *    mark the square and put is back
 *    update the board
 * 2. Update the next_subgrid(active subgrid) and player turn
 *    check whether in the subgrid someone is won
 *    if no, the active subgrid is in the same relative position as the click one
 *    and player turn should be changed(by Player.toggle)
 *    if yes, any subgrid can be operated on next turn, and current player can continue to play
 */