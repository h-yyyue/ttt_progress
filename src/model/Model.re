/*
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
 * Model.subgrid
 * Model.subgrid_winner
 * Model has an active subgrid which indicates which subgrid is currently being played
 * Update will receive two indexes, one for the subgrid and one for the square
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

/*
 * Except for modification to board structure, 
 * active_subgrid also need to be recorded
 */
let init: t = {player_turn: X, board: empty_grid};

/*
 * current winner will only be a subgrid winner with our new structure
 */
let winner = (grid: grid): option((Player.t, Grid.three_in_a_row)) =>
  Grid.threes_in_a_row
  |> List.filter_map(three_in_a_row => {
       let (square0, square1, square2) =
         three_in_a_row |> Triple.map(i => grid |> Grid.get_item(i));
       switch (square0, square1, square2) {
       | (Marked(p0), Marked(p1), Marked(p2)) when p0 == p1 && p1 == p2 =>
         Some((p0, three_in_a_row))
       | _ => None
       };
     })
  |> (
    fun
    | [] => None
    | [winner, ..._] => Some(winner)
  );

/*
 * We need a new function for grid winner!
 * Don't directly copy the code from subgrid_winner and check whether each node is a winner
 * redraw each node with the result of subgrid_winner and use subgrid_winner for the redrawed board instead
 */
 

         