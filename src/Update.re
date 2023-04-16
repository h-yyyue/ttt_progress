module Action = {
  [@deriving sexp]
  type t =
    | MarkSquare(Grid.index, Grid.index);
};

/*
 * Goal: update the board and player turn
 * Hint:
 * 1. use 'Grid.get_item' to get the modifies subgrid from 'model.board'
 * 2. update the subgrid by 'Grid.put_item'
 * 3. put the subgrid back to the board by 'Grid.put_item'
 *
   then update the 'next_subgrid'(active subgrid) and 'player turn'
 * 4. check whether in the modified subgrid someone is won (Model.subgrid_winner)
 * 5. if no
      active subgrid: same index in the board as the square in the subgrid
      player turn changed by Player.toggle
 *    if yes
      any subgrid can be operated on next turn(just set it None)
      current player continues to play
  * 6. return the updated model

 * let update = (action: Action.t, model: Model.t): Model.t => TODO
 * Note that Model.t contains:
   {
   board: grid,
   active_subgrid: option(Grid.index),
   player_turn: Player.t,
   }
 */