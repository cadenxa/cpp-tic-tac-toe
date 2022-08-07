#include <iostream>

// boardRender.cpp
std::string boardRender(int board[3][3]); // Turns the board array into a string that can be displayed 
int translatePlayerInputCoord(std::string playerInput, int arrayDimension); // Turns capital letter or number in string into row or column in the board[3][3] array

// checks.cpp
bool validatePlayerInput(std::string playerInput); // Will check if input is valid so the program can ask for input again if not
bool canPlayerPlace (int board[3][3], int row, int column); // If the spot on the board is occupied, return false so game() will ask the player to put in another spot
bool checkWinConditions(int board[3][3]);
// Checks for a horizontal win condition
// Checks for a vertical win condition
// Checks for the first diagonal
// Checks for the second diagonal
// If it hasn't returned yet, there has not yet been a win condition
bool isBoardFilled(int board[3][3]); // Checks for if there are any empty spaces (elements that are 0) and if not, the board is full

// game.cpp
int game(); // main player turn loop
int changePlayer(int activePlayer); // Returns the player number whose turn it is next

// main.cpp
void instructions();
// main() calls instructions, runs game() 3 times and calculates the winner for the best of 3.