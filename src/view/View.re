module Vdom = Virtual_dom.Vdom;

let svg = Vdom.Node.create_svg;
let attr = Vdom.Attr.create;

let blank_square =
  Vdom.Node.div(
    [Vdom.Attr.classes(["square"])],
    [
      svg(
        "svg",
        [attr("viewBox", "0 0 24 24")],
        [
          svg(
            "rect",
            [
              attr("width", "24"),
              attr("height", "24"),
              attr("fill", "none"),
              attr("stroke", "black"),
              attr("stroke-width", "0.5"),
            ],
            [],
          ),
        ],
      ),
    ],
  );

let view_of_square =
    (
      ~inject: Update.Action.t => Vdom.Event.t,
      ~index: int,
      square: Model.square,
    )
    : Vdom.Node.t =>
  switch (square.status) {
  | Unmarked =>
    let click_handlers = [
      Vdom.Attr.on_click(_ => inject(Update.Action.MarkSquare(index))),
    ];
    Vdom.Node.div(
      [Vdom.Attr.classes(["square"]), ...click_handlers],
      [blank_square],
    ); //add empty box
  | Marked(p) =>
    Vdom.Node.div(
      [Vdom.Attr.classes(["square"])],
      [PlayerMark.view(p, square.winning)],
    )
  };

let view = (~inject, model: Model.t) => {
  let board = Model.makeBoard(model);
  let rec mksquare = (sqlst: list(Model.square), index) => {
    switch (sqlst) {
    | [] => []
    | [sq, ...rest] =>
      let sqview = view_of_square(~inject, ~index, sq);
      [sqview, ...mksquare(rest, index + 1)];
    };
  };
  let squares = mksquare(board.squarelst, 0);

  Vdom.Node.div(
    [Vdom.Attr.id("board")],
    [Vdom.Node.div([Vdom.Attr.classes(["grid"])], squares)],
  );
};
