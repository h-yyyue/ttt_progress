type square = {
  marked: option(Player.t),
  winning: bool,
};

type grid = list(square);
type t = {
  grid,
  player_turn: Player.t,
};

// You may need this:

let init: t;

let squares: t => list(square);
let player_turn: t => Player.t;

// required by Incr_dom
let cutoff: ('a, 'a) => bool;
