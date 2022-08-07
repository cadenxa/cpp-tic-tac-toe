#include "tictactoe.hpp"
#include <iostream>

int game(){

  int activePlayer = 1; // 1 for X, 2 for O
  int board[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};

  // Max 100 turns to prevent infinite loop, returns as a draw if the turns run out.
  for (int turnsCount = 0; turnsCount < 100; turnsCount++) {

    // render board function
    std::cout << boardRender(board);

    // take player input and make sure it is valid
    bool validInput = false;
    bool canPlace = false; 
    std::cout << "\nPlayer " << activePlayer << ": Your move.\n";
    std::cout << "Enter your move as a capital letter indicating column and a number indicating row (example: A1): ";
    std::string playerInput;
    std::cin >> playerInput;
    if (!validatePlayerInput(playerInput)){
    std::cout << "Invalid input. Please try again. Did you make sure there are no spaces?\n";
    }
      else {
    // translate letter number to board position function
      int row = translatePlayerInputCoord(playerInput, 1);
      int column = translatePlayerInputCoord(playerInput, 0);
      // check if spot is taken
      if (!canPlayerPlace(board, row, column)) {
        std::cout << "That spot is taken! Please try again.\n";
        canPlace = false;
      }
      else {
      // place x or o
      board[row][column] = activePlayer;

    // check for win
    if (checkWinConditions(board)){
      std::cout << "Congratulations, Player " << activePlayer << "! You win!\n\n";
      return activePlayer;
    }

    // check for draw
    if (isBoardFilled(board)) {
      std::cout << "The board is full and there is no winner. This game has ended in a draw. Good game!\n\n";
      return 0;
    }
  
    activePlayer = changePlayer(activePlayer);
      }
    }
  }
  return 0;
}

//

int changePlayer(int activePlayer){ // Returns the player number whose turn it is next
  if (activePlayer == 1){activePlayer=2;}
  else {activePlayer = 1;}
  return activePlayer;
}