

#include <vector>
#include <memory>

#include "BasicGOL.h"
#include "GameOfLife.h"

using namespace std;

//constructor using GameOfLife inheritance
BasicGOL::BasicGOL(int width, int height, std::string gameBoard)
	:GameOfLife(width, height, gameBoard)
{

}

void BasicGOL::NextGen() {
	vector<int> temporaryBoard(width * height);

	//iterate through each cell
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			int liveNeighbors = countLiveNeighbors(row, col); //count through each live cell as we iterate
			int index = row * width + col;
			int current = board[index]; // current cell 


			//Rules of the game
			int nextValue = 0;

			if (current == 1) {
				if (liveNeighbors == 2 || liveNeighbors == 3) {
					nextValue = 1;
				}
				else {
					nextValue = 0;
				} // end nested if else loop
			}
			else {
				if (liveNeighbors == 3) {
					nextValue = 1;
				}
			} // end mail if else loop

			temporaryBoard[index] = nextValue;


		} // end nested for loop
	} // end first for loop

	//Replace the board
	board = temporaryBoard;
	++currentGeneration;

}  //end nextGen() function

//Clone
std::shared_ptr<GameOfLife> BasicGOL::clone() const {
	return make_shared<BasicGOL>(*this);
}

std::shared_ptr<GameOfLife> makeStandard(int width, int height, std::string gameBoard) {
	return make_shared<BasicGOL>(width, height, gameBoard);
}







