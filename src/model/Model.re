type status =
  | Unmarked
  | Marked(Player.t);

type square = {
  status: status,
  winning: bool,
};

type t = unit;

type board = {
  squarelst: list(square),
  player_turn: Player.t,
};

// required by Incr_dom
let cutoff = (===);

let init: t = failwith("todo");

let makeBoard = failwith("todo");
