type status =
  | Unmarked
  | Marked(Player.t);

type square = {
  status,
  winning: bool,
};

type index = int;
type grid = list(status);

type t = {
  grid,
  player_turn: Player.t,
};

type board = {
  squarelst: list(square),
  player_turn: Player.t,
};

let get_item: (grid, index) => status;

// required by Incr_dom
let cutoff: ('a, 'a) => bool;

let init: t;

let makeBoard: t => board; //used in view
