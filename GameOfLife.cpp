


#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "GameOfLife.h"

using namespace std;

//CONTRUCTOR
GameOfLife::GameOfLife(int width, int height, const std::string& gameString)
	: height(height), 
	width(width),
	currentGeneration(0), 
	board(width * height)

{
	//make sure that height and width make sense or throws error
	if (height <= 0 || width <= 0) {
		throw invalid_argument("Invalid board dimensions!");
	}

	if (gameString.size() != static_cast<size_t>(width * height)) {
		throw invalid_argument("Board size is off, it needs ot match the dimensions!");
	}

	//we fill out the board here because we can access width and height after
	// we define them in the constructor
	// we also turn strings into ints
	for (int i = 0; i < width * height; ++i) {
		if (gameString[i] == 'O') {
			board[i] = 1;
		}
		else if (gameString[i] == 'X') {
			board[i] = 0;
		}
		else if (gameString[i] == 'D') {
			board[i] = 2;
		}
		else {
			throw invalid_argument("Invalid character in board!");
		}
	}
}   // end CONSTRUCTOR

//PRINTGAME
void GameOfLife::PrintGame() const {
	cout << "Generation: " << currentGeneration << endl;
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col){
			int index = row * width + col;

			if (board[index] == 2) {
				cout << 'D';
			}
			else {
				cout << board[index];
			}			
		}
		cout << '\n';
	}
} // end printGame()

int GameOfLife::countLiveNeighbors(int row, int col) const {  //we make it a const to avoid modification of original board
	int count = 0;

	//we check cell with indexes near it in this manner:
	//(-1,1)/(0,1)/(1,1)
	//(-1,0)/(0,0)/(1,0)
	//(-1,-1)/(0,-1)/1,-1)
	//We use a nexted for loop to update the index
	for (int deltaRow = -1; deltaRow <= 1; ++deltaRow) {
		for (int deltaCol = -1; deltaCol <= 1; ++deltaCol) {
			if (deltaRow == 0 && deltaCol == 0) {
				continue; // we skip the center cell at 0,0
			}

			//we add because it is relative to the actual cell where we are standing
			int neighborRow = row + deltaRow;
			int neighborCol = col + deltaCol;

			// we need to check our bounds to make sure that we are not out bounds
			if (neighborRow < 0 || neighborRow >= height ||
				neighborCol < 0 || neighborCol >= width) {
				continue;
			}

			//lets read the current cell and decide whehter it is alive or dead
			
			int neighborIndex = neighborRow * width + neighborCol;
			if (board[neighborIndex] == 1) {
				// we increment how many are alive
				++count;
			}
		}
	}

	return count;

}   // end countLiveNeighbors

void GameOfLife::NextNGen(int n) {
	// do nothign if it equals 0
	// we do not explicitly handle 0, because it runs NextGen zero times
	if (n < 0) {
		throw invalid_argument("That is an invalid argument Generation!");
	}
	
	// we call next n amount of times
	for (int i = 0; i < n; ++i) {
		NextGen();
	}	
}  // end of nextNGen

//Toggle by flat index
void GameOfLife::ToggleCell(int index) {
	if (index < 0 || index >= static_cast<int>(board.size())) {
		throw out_of_range("Index is of Range!");
	}

	if (board[index] == 1) {
		board[index] = 0;
	}
	else {
		board[index] = 1;
	}
}

//Toggle by row and columnt
void GameOfLife::ToggleCell(int row, int col) {
	if (row < 0 || row >= height) {
		throw out_of_range("Invalid board dimensions!");
	}

	if (col < 0 || col >= width) {
		throw out_of_range("Invalid board dimensions!");
	}

	int index = row * width + col;
	ToggleCell(index);

}

GameOfLife& GameOfLife::operator+=(int gens) {
	NextNGen(gens);
	return *this;
}

// We return a copy to a local object
std::shared_ptr<GameOfLife> GameOfLife::operator+(int gens) const {
	auto copy = clone();
	copy->NextNGen(gens);
	return copy;
}

GameOfLife& GameOfLife::operator++() {
	NextGen();
	return *this;
}

	
	
