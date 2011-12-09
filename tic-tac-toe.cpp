/**
 *
 * Author: Mohammed M Ahmed
 * Email: m@rinum.com
 * Website: http://rinum.com
 *
 * File: tic-tac-toe.cpp
 * 
 * Tic-Tac-Toe
 * All possible game states.
 **/

#include "tic-tac-toe.h"

void traverse(ofstream &fout, Game *&game){

  /* Save to file */
  fout << "{ \"parentID\" : \"" << game->parent << "\", \"ID\" : \"" << game << "\", \"board\" : [";
  for(int i=0; i<(int)game->gameState.size(); i++){
    fout << "[";
    for(int j=0; j<(int)game->gameState[i].size(); j++){
      switch(game->gameState[i][j]){
      case 0:
	fout << "\"X\"";
	break;
      case 1:
	fout << "\"O\"";
	break;
      default:
	fout << "\" \"";
	break;
      }
      if( j < 2 )
	fout << ",";
    }
    fout << "]";
    if( i < 2 )
      fout << ",";
  }
  fout << "]}," << endl;

  for(int i=0; i<(int)game->children.size(); i++)
    traverse(fout, game->children[i]);

}

void brancher(Game *&parent, int player){
  player %= PLAYERS; //This player moves now
  vector<Position *> validMoves = findValidMoves(parent);

  for(int i=0; i<(int)validMoves.size(); i++){
    Position *move = validMoves[i];
    Game *t = new Game;
    t->gameState = parent->gameState;
    t->parent = parent;
    t->gameState[move->r][move->c] = player; //make move
    parent->children.push_back(t);

    if(checkState(t))//checks if game over (is there a point in continuing?)
      brancher(t, player + 1);    
  }
}

int checkState(Game *&board){
  /* check if game over */

  //check rows
  for(int r=0; r<(int)board->gameState.size(); r++){
    if( (board->gameState[r][0] == board->gameState[r][1]) && ( board->gameState[r][1] == board->gameState[r][2]) && board->gameState[r][1] != -1)
      return 0;
  }

  //check cols
  for(int c=0; c<(int)board->gameState.size(); c++){
    if( (board->gameState[0][c] == board->gameState[1][c]) && ( board->gameState[1][c] == board->gameState[2][c]) && board->gameState[1][c] != -1)
      return 0;
  }

  //check diags
  if( (board->gameState[0][0] == board->gameState[1][1]) && ( board->gameState[1][1] == board->gameState[2][2]) && board->gameState[1][1] != -1)
    return 0;

  if( (board->gameState[0][2] == board->gameState[1][1]) && ( board->gameState[1][1] == board->gameState[2][0]) && board->gameState[1][1] != -1)
    return 0;

  return 1;
}

vector<Position* > findValidMoves(Game *&board){
  vector<Position *> validMoves;
  for(int i=0; i<(int)board->gameState.size(); i++)
    for(int j=0; j<(int)board->gameState[i].size(); j++)
      if(board->gameState[i][j] == -1)
	validMoves.push_back(new Position(i,j));

  return validMoves;
}
