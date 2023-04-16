type t('item) = Triple.t(Triple.t('item));

[@deriving sexp]
type index = (Triple.index, Triple.index);

/*
 * Goal: get item from a grid, and put item into a grid.
 * 
 * let get_item = ((r, c): index, grid: t('item)) : 'item => TODO
 * let put_item = ((r, c): index, item: 'item, grid: t('item)) : t('item) => TODO
 * 
 * Hint: use Triple.get_component and Triple.put_component.
 */


/*
 * Goal: make a list of all possible indices, (or check function, feel free to design by your methods)
         make a list of all triple of indices that win a tic tac toe game.
 * 
 * let index_list = TODO
 * let threes_in_a_row = TODO
 */


[@deriving sexp]
type three_in_a_row = Triple.t(index);


/*
 * Goal: apply a function to all items in a grid, and output a new grid.
 * 
 * let map = (f: 'item1 => 'item2, grid: t('item1)): t('item2) => TODO
 * 
 * Hint: use Triple.map.
 */
