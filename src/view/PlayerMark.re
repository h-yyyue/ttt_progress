module Vdom = Virtual_dom.Vdom;

let svg = Vdom.Node.create_svg;
let attr = Vdom.Attr.create;
let square = (w: bool) =>
  svg(
    "rect",
    [
      attr("width", "24"),
      attr("height", "24"),
      w
        ? attr("fill", "rgba(100, 10, 0, 0.1)")
        : attr("fill", "rgba(0, 0, 0, 0)"),
    ],
    [],
  );

let view = (p: Player.t, w: bool): Vdom.Node.t =>
  switch (p) {
  | X =>
    Vdom.Node.div(
      [Vdom.Attr.classes(["player-mark"])],
      [
        svg(
          "svg",
          [attr("viewBox", "0 0 24 24")],
          [
            Vdom.Node.create_svg(
              "line",
              [
                attr("x1", "18"),
                attr("y1", "6"),
                attr("x2", "6"),
                attr("y2", "18"),
              ],
              [],
            ),
            Vdom.Node.create_svg(
              "line",
              [
                attr("x1", "6"),
                attr("y1", "6"),
                attr("x2", "18"),
                attr("y2", "18"),
              ],
              [],
            ),
            square(w),
          ],
        ),
      ],
    )
  | O =>
    Vdom.Node.div(
      [Vdom.Attr.classes(["player-mark"])],
      [
        svg(
          "svg",
          [attr("viewBox", "0 0 24 24")],
          [
            Vdom.Node.create_svg(
              "circle",
              [attr("cx", "12"), attr("cy", "12"), attr("r", "7")],
              [],
            ),
            square(w),
          ],
        ),
      ],
    )
  };
