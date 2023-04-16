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

/*
 * Goal: make empty_grid suitable for Meta tic tac toe
 *       you may define empty_subgrid first 
 */
let empty_grid = (
  (Unmarked, Unmarked, Unmarked),
  (Unmarked, Unmarked, Unmarked),
  (Unmarked, Unmarked, Unmarked),
);// TODO

let init: t = {player_turn: X, active_subgrid: None, board: empty_grid};
    

/*
 * Goal: let subgrid_winner return the winner of a subgrid, i,e. option((Player.t, Grid.three_in_a_row)), None if no winner
 *
 * Hint: (only for reference, you can use other methods)
         1. traverse 'Grid.threes_in_a_row', use List.filter_map to filter out the 'Grid.three_in_a_row' which is not a winner
         2. for each 'Grid.three_in_a_row', use 'Grid.get_item' to get the player of each square, use 'Triple.map' to get the triple of players
         3. check if the content in the triple is the same, if so, return the player as well as the 'Grid.three_in_a_row'. Otherwise, return None.
 */

//let subgrid_winner = (subgrid: subgrid): option((Player.t, Grid.three_in_a_row)) => TODO
