#include "tictactoe.hpp"
#include <iostream>

bool validatePlayerInput(std::string playerInput) { // Will check if input is valid so the program can ask for input again if not
  if (playerInput.size() != 2) {
    return false;
  }
  if (playerInput[0] != 'A' && playerInput[0] != 'B' && playerInput[0] != 'C') {
    return false;
  }
  if (playerInput[1] != '1' && playerInput [1] != '2' && playerInput[1] != '3') {
    return false;
  }
  return true;
}

//

bool canPlayerPlace (int board[3][3], int row, int column) { // If the spot on the board is occupied, ask the player to put in another spot
  int playerPosition[2] = {row, column};
  if(board[playerPosition[0]][playerPosition[1]] == 1 || board[playerPosition[0]][playerPosition[1]] == 2) {
    return false;
  }
  return true;
}

//

bool checkWinConditions(int board[3][3]){

  // Checks for a horizontal win condition
  for (int row = 0; row < 3; row++) {
    if (board[row][0] == board[row][1] && board[row][0] == board[row][2] && board[row][0] != 0){
      return true;
    }
  }
  // Checks for a vertical win condition
  for (int column = 0; column < 3; column++){
    if (board[0][column] == board[1][column] && board[0][column] == board[2][column] && board[0][column] != 0 ) {
      return true;
    }
  }
  // Checks for the first diagonal
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0]!= 0){return true;}
  // Checks for the second diagonal
  if (board[0][2] == board [1][1] && board[0][2] == board[2][0] && board[0][2]!= 0 ){return true;}
  // If it hasn't returned yet, there has not yet been a win condition
  return false;
}

//

bool isBoardFilled(int board[3][3]){ // Checks for if there are any empty spaces (elements that are 0) and if not, the board is full
  bool isBoardFilled = true;
  for (int row = 0; row < 3; row++){
    for (int column = 0; column < 3; column ++){
      if (board[row][column] == 0){
        isBoardFilled = false;}
    }
  }
  return isBoardFilled;
}