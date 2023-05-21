type status =
  | Unmarked
  | Marked(Player.t);

type square = {
  status: status,
  winning: bool,
};


type t;

type board = {
  squarelst: list(square),
  player_turn: Player.t,
};

// required by Incr_dom
let cutoff: ('a, 'a) => bool;

let init: t;

let makeBoard: t => board; //used in view
