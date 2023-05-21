module Action: {
  [@deriving sexp]
  type t ;
};

let update: (Action.t, Model.t) => Model.t;
