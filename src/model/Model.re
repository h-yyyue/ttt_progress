type square = {
  marked: option(Player.t),
  winning: bool,
};

type t = unit;

// You may need this:
// let init: t;
let squares = failwith("todo");
let player_turn= failwith("todo");

// required by Incr_dom
let cutoff = (===);
