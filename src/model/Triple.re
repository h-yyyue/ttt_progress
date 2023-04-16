open Sexplib.Std;

[@deriving sexp]
type t('c) = ('c, 'c, 'c);

[@deriving sexp]
type index = int;

/*
 * Goal: get and put components of a truple.
 * let get_component = (i : index, (c0, c1, c2) : t('c)) : 'c => TODO
 * let put_component = (i : index, c : 'c, (c0, c1, c2) : t('c)) : t('c) => TODO
 */


let map = (f, (c0, c1, c2)) => (f(c0), f(c1), f(c2));
