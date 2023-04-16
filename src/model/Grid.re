type t('item) = Triple.t(Triple.t('item));

[@deriving sexp]
type index = (Triple.index, Triple.index);

/*
 * Goal: get item from a grid and return the item, 
         put item into a grid and return the new grid.
 * 
 * Hint: use Triple.get_component and Triple.put_component.
 */

//let get_item = ((r, c): index, grid: t('item)) => TODO

//let put_item = ((r, c): index, item: 'item, grid: t('item)) => TODO



/*
 * Goal: In View.re, we need to traverse all indixes to draw each of them.(using List.map).
         Generate a list of all possible indices in a grid.
 */

//let index_list : list(index) = TODO

 /*
  * Goal: When checking whether a player wins, we need to traverse all triples of indixes in a line
         Generate a list of all triples of indices that win a tic tac toe game.
  */

[@deriving sexp]
type three_in_a_row = Triple.t(index);

 //let threes_in_a_row : list(three_in_a_row) = TODO


/*
 * Goal: map a function to all items in a grid, and output ths new grid.
 * 
 * Hint: use Triple.map.
 */

//let map = (f: 'item1 => 'item2, grid: t('item1)) => TODO