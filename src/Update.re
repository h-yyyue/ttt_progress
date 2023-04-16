module Action = {
  [@deriving sexp]
  type t =
    | MarkSquare(Grid.index, Grid.index);
};
