/*
 * Some functions or types you have defined in the previous part:
 * Triple.t('a) = ('a, 'a, 'a)
 * Triple.index = 0 | 1 | 2
 * Triple.get_component: (Triple.index, Triple.t('a)) => 'a
 * Triple.put_component: (Triple.index, 'a, Triple.t('a)) => Triple.t('a)
 * Triple.map(('a => 'b), Triple.t('a)) = Triple.t('b)
 *
 * Grid.t('item) = Triple.t(Triple.t('item))
 * Grid.index = (Triple.index, Triple.index)
 * Grid.get_item: (Grid.index, Grid.t('item)) => 'item
 * Grid.put_item: (Grid.index, 'item, Grid.t('item)) => Grid.t('item)
 * Grid.three_in_a_row = (Grid.index, Grid.index, Grid.index)
 * Grid.threes_in_a_row: a list of all possible three_in_a_row which wins the game
 * Grid.map(('item => 'item'), Grid.t('item)) => Grid.t('item)
 * 
 * Player.t = X | O
 * Player.toggle: Player.t -> Player.t
 * 
 */

type square =
  | Unmarked
  | Marked(Player.t);

/*
 * Goal: add new type subgrid and modify grid
 */
type grid = Grid.t(square); // TODO

/*
 * Rule: if active_subgrid is None, then the player can mark any square in the board
         if active_subgrid is Some(index), then the player can only mark the square in the subgrid with the index
 *       if the player marks a square in a subgrid and doesn't win in that subgrid, then the active_subgrid becomes the index of the square in its subgrid
         if win, then the active_subgrid becomes None
 */
type t = {
  board: grid,
  active_subgrid: option(Grid.index),
  player_turn: Player.t,
};

// required by Incr_dom
let cutoff = (===);

let empty_grid = (
  (Unmarked, Unmarked, Unmarked),
  (Unmarked, Unmarked, Unmarked),
  (Unmarked, Unmarked, Unmarked),
);// TODO

let init: t = {player_turn: X, active_subgrid: None, board: empty_grid};
    