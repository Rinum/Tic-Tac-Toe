/**
 *
 * Author: Mohammed M Ahmed
 * Email: m@rinum.com
 * Website: http://rinum.com
 *
 * File: tic-tac-toe.h
 * 
 * Tic-Tac-Toe
 * All possible game states.
 **/

#include <fstream>
#include <vector>

#ifndef TICTACTOE_H
#define TICTACTOE_H

#define PLAYERS 2
using namespace std;

struct Game{
  vector<vector<int> > gameState; //The current game state (board)
  Game *parent; //Parent state
  vector<Game *> children; //Array of children states
};

struct Position{
  Position(int x, int y){
    r = x; 
    c = y;
  }
  int r;
  int c;
};

void brancher(Game *&parent, int player);
void traverse(ofstream &fout, Game *&game);
vector<Position *> findValidMoves(Game *&board);
int checkState(Game *&board);

#endif
