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

