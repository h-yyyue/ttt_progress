type status =
  | Unmarked
  | Marked(Player.t);

type square = {
  status,
  winning: bool,
};

type index = int;
type grid = list(status);

type t = {
  grid,
  player_turn: Player.t,
};

type board = {
  squarelst: list(square),
  player_turn: Player.t,
};

let blank_grid = [
  Unmarked,
  Unmarked,
  Unmarked,
  Unmarked,
  Unmarked,
  Unmarked,
  Unmarked,
  Unmarked,
  Unmarked,
];
let rec get_item = (lst: grid, index: index): status =>
  switch (lst, index) {
  | ([x, ..._], 0) => x
  | ([_, ...xs], n) => get_item(xs, n - 1)
  | ([], _) =>
    failwith("get_item: index out of bounds " ++ string_of_int(index))
  };

// required by Incr_dom
let cutoff = (===);

let init = {grid: blank_grid, player_turn: Player.X};

let line: list((index, index, index)) = [
  (0, 1, 2),
  (3, 4, 5),
  (6, 7, 8),
  (0, 3, 6),
  (1, 4, 7),
  (2, 5, 8),
  (0, 4, 8),
  (2, 4, 6),
];

let rec dye_board = (squarelst: list(square), n: index): list(square) => {
  switch (squarelst, n) {
  | ([], _) => []
  | ([x, ...xs], 0) =>
    let {status, _} = x;
    [{status, winning: true}] @ xs;
  | ([x, ...xs], n) => [x] @ dye_board(xs, n - 1)
  };
};

let makeBoard = ({grid, player_turn}: t) => {
  let squarelst =
    grid
    |> List.map(status => {
         switch (status) {
         | Unmarked => {status: Unmarked, winning: false}
         | Marked(p) => {status: Marked(p), winning: false}
         }
       });

  line
  |> List.filter_map(tri => {
       let (i, j, k) = tri;
       let a = get_item(grid, i);
       let b = get_item(grid, j);
       let c = get_item(grid, k);
       switch (a, b, c) {
       | (Unmarked, _, _) => None
       | (_, Unmarked, _) => None
       | (_, _, Unmarked) => None
       | (Marked(p), Marked(q), Marked(r)) =>
         if (p == q && q == r) {
           Some((i, j, k));
         } else {
           None;
         }
       };
     })
  |> (
    fun
    | [] => {squarelst, player_turn}
    | [w, ..._] => {
        let (i, j, k) = w;
        let squarelst = dye_board(squarelst, i);
        let squarelst = dye_board(squarelst, j);
        let squarelst = dye_board(squarelst, k);
        {squarelst, player_turn};
      }
  );
};
