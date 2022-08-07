#include "tictactoe.hpp"
#include <iostream>

std::string boardRender(int board[3][3]){ // Turns the board array into a string that can be displayed

  // INITIALIZE string boardString
  std::string boardString = "\n  A B C\n"; // column labels row is fairly straightforward

  // ITERATE OVER each row
  for (int row = 0; row < 3; row++){
    
    boardString = boardString + std::to_string(row+1); // row label column

    // ITERATE OVER column in each row
    for (int column = 0; column < 3; column++){
      switch (board[row][column]){
        case 1: // If Player 1 occupies a spot, put an X there
          boardString = boardString + " X";
          break;
           
        case 2: // If Player 2 occupies a spot, put an O there
          boardString = boardString + " O";
          break; 

        default: // If neither players 1 nor 2 occupy a spot, put a space there
          boardString = boardString + "  ";
          break; 
      }
    }
    boardString = boardString + "\n"; // Adds a newline at the end of each row
  }

  return boardString;
}

//

int translatePlayerInputCoord(std::string playerInput, int arrayDimension) { // Turns capital letter or number in string into row or column in the board[3][3] array
  int coord;
  switch (playerInput[arrayDimension]) {
    case '1':
      coord = 0;
      break;
    case '2':
      coord = 1;
      break;
    case '3':
      coord = 2;
      break;
    case 'A':
      coord = 0;
      break;
    case 'B':
      coord = 1;
      break;
    default: // case 'C'
      coord = 2;
      break;
  }
  return coord;
}