module Action = {
  [@deriving sexp]
  type t =
    | MarkSquare(Grid.index);
};

/*
 * Goal: update the board and player turn
 * Hint:
 * 1. use 'Grid.get_item' to get the modifies grid from 'model.board'
 * 2. update the grid by 'Grid.put_item'
 * 3. put the grid back to the board by 'Grid.put_item'
 * 4. toggle the player turn
 *

 * let update = (action: Action.t, model: Model.t): Model.t => TODO
 * Note that Model.t contains:
   {
   board: grid,
   player_turn: Player.t,
   }
 */