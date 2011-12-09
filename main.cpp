/**
 *
 * Author: Mohammed M Ahmed
 * Email: m@rinum.com
 * Website: http://rinum.com
 *
 * File: main.cpp
 * 
 * Tic-Tac-Toe
 * All possible game states.
 **/

#include <fstream>
#include <vector>
#include "tic-tac-toe.h"

int main(){
  ofstream fout("output.dat");

  /* Initialize the board */
  vector<vector<int> > board( 3, vector<int>( 3, -1 ) );

  /* Create new game */
  Game *TicTacToe = new Game();
  TicTacToe->gameState = board;
  TicTacToe->parent = NULL;

  /* Play game (all possible scenarios) */
  brancher(TicTacToe,0); //Player 0 (X) goes first

  /* Save to file */
  traverse(fout, TicTacToe);

  return 0;
}
