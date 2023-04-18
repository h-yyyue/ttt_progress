open Sexplib.Std;

[@deriving sexp]
type t('c) = ('c, 'c, 'c);

[@deriving sexp]
type index = int;

/*
 * Start from here!
 * Goal: get a component of a truple and return the component;
         put(update) a component of a triple and return the new triple.
 * Hint: if you use switch to match the index and return the component, use _two instead of 2 to avoid the not exhausted warning.
 */

//let get_component = (i : index, (c0, c1, c2) : t('c)) => TODO

//let put_component = (i : index, c : 'c, (c0, c1, c2) : t('c)) => TODO
//                                ^----the component to be put

let map = (f, (c0, c1, c2)) => (f(c0), f(c1), f(c2));
