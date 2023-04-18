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

type grid = Grid.t(square);


type t = {
  board: grid,
  player_turn: Player.t,
};

// required by Incr_dom
let cutoff = (===);


let empty_grid = (
  (Unmarked, Unmarked, Unmarked),
  (Unmarked, Unmarked, Unmarked),
  (Unmarked, Unmarked, Unmarked),
);


let init: t = {player_turn: X, board: empty_grid};

/*
 * Goal: let grid_winner return the winner of a grid, i,e. option((Player.t, Grid.three_in_a_row)), None if no winner
 *
 * Hint: (only for reference, you can use other methods)
         1. traverse 'Grid.threes_in_a_row', use List.filter_map to filter out the 'Grid.three_in_a_row' which is not a winner
         2. for each 'Grid.three_in_a_row', use 'Grid.get_item' to get the content of each square, use 'Triple.map' to get the triple of square state in a line
         3. check if the content in the triple is the same, if so, return the player as well as the 'Grid.three_in_a_row'. Otherwise, return None.
 */

//let grid_winner = (grid: grid): option((Player.t, Grid.three_in_a_row)) => TODO



