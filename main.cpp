#include "tictactoe.hpp"
#include <iostream>

// The tic tac toe board will always be 3x3, so it's better to use an array than a vector
// 0 is for empty, 1 is for P1(X), and 2 is for P2(O)
// int board[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}}

// How the board will look: 
/*

  A B C
1 X O X
2 O   O  
3 X O X  

*/

void instructions(){
  
  std::cout << "Welcome to Tic Tac Toe!\n\n";
  std::cout << "Two players will play by taking turns typing into the same terminal.\n";
  std::cout << "The game will end when 3 tiles on the 3x3 board in a row are filled by the same player, or when the board is full.\n";
  std::cout << "This is a best of 3.\n\n";

}

//

int main() {  

  instructions();

  bool isEnd = false;
  int p1Score = 0;
  int p2Score = 0;

  for (int games = 0; games < 3; games++) {
      std::cout << "Game " << games+1 << ": Start!\n";
      int winner = game();
      if (winner == 1) {p1Score++;}
      else if (winner == 2) {p2Score++;}
    }
  
  if (p1Score > p2Score) {std::cout << "Player 1 wins! Thanks for playing!\n";}
  else if (p1Score < p2Score) {std::cout << "Player 1 wins! Thanks for playing!\n";}
  else {std::cout << "This best of 3 has ended in a draw. Thanks for playing!\n";}
  return 0;
}