type t('item) = Triple.t(Triple.t('item));

[@deriving sexp]
type index = (Triple.index, Triple.index);


