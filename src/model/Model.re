/*
 * Some functions you can use:
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
 * Player.toggle: Player.t -> Player.t, change to the other player
 * 
 */

type square =
  | Unmarked
  | Marked(Player.t);

/*
 * Goal: add subgrid and modify grid
 */
type grid = Grid.t(square); 

type t = {
  board: grid,
  active_subgrid: option(Grid.index),
  player_turn: Player.t,
};

// required by Incr_dom
let cutoff = (===);

/*
 * Goal: let empty_grid suitable for Meta tic tac toe
 */
let empty_grid = (
  (Unmarked, Unmarked, Unmarked),
  (Unmarked, Unmarked, Unmarked),
  (Unmarked, Unmarked, Unmarked),
);

let init: t = {player_turn: X, active_subgrid: None, board: empty_grid};

/*
 * Goal: let subgrid_winner return the winner of a subgrid, 
 *
 * Hint: (only for reference, you can use other methods)
         1. traverse 'Grid.threes_in_a_row', use List.filter_map to filter out the 'Grid.three_in_a_row' which is not a winner
         2. for each 'Grid.three_in_a_row', use 'Grid.get_item' to get the player of each square, use 'Triple.map' to get the triple of players
         3. check if the content of the triple is the same, if so, return the player as well as the 'Grid.three_in_a_row'. Otherwise, return None.
 * let subgrid_winner = (subgrid: subgrid): option((Player.t, Grid.three_in_a_row)) => TODO
 */


/*
 * Goal: let grid_winner returning the winner of the whole board
 * Hint: 1. use 'Grid.map' to check each subgrid
 *       2. redraw each node with the result of subgrid_winner 
         3. use subgrid_winner for the redrawed board
  * let grid_winner = (grid: grid): option((Player.t, Grid.three_in_a_row)) => TODO
 */
 

         