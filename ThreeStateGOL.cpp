


#include "ThreeStateGOL.h"

#include <vector>
#include <stdexcept>
#include <memory>

using namespace std;


ThreeStateGOL::ThreeStateGOL(int width, int height, std::string gameBoard)
	:GameOfLife(width, height, std::string(width* height, 'X'))
{
	if (width <= 0 || height <= 0) {
		throw invalid_argument("Invalid board dimensions..");
	}

	if (gameBoard.size() != static_cast<size_t>(width * height)) {
		throw invalid_argument("Board size needs to match dimensions..");
	}

	for (int i = 0; i < width * height; ++i) {
		if (gameBoard[i] == 'X') {
			board[i] = 0;
		} 
		else if (gameBoard[i] == 'O') {
			board[i] = 1;
		} 
		//we incorpoarte D for decaying, since this is accepted for ThreeStateGOL
		else if (gameBoard[i] == 'D') {
			board[i] = 2;
		}
		else {
			throw invalid_argument("Invalid character board!");
		}
	}

}

//Three State Rules
void ThreeStateGOL::NextGen() {
	std::vector<int> temporaryBoard(width * height);

	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			int index = row * width + col;
			int current = board[index];
			int liveNeighbors = countLiveNeighbors(row, col);

			int nextValue = 0;

			if (current == 1) {
				if (liveNeighbors == 2 || liveNeighbors == 3) {
					nextValue = 1;
				}
				else {
					nextValue = 2;
				}
			}
			else if (current == 2) {
				// Decaying cells
				if (liveNeighbors == 3) {
					nextValue = 1;
				}
				else if (liveNeighbors == 2)
				{
					nextValue = 2;
				}
				else {
					nextValue = 0;
				}
			} // end else if for Decaying
			else {
				//Dead
				if (liveNeighbors == 3) {
					nextValue = 2;
				}
				else {
					nextValue = 0;
				}
			}

			temporaryBoard[index] = nextValue;

		}
	}
	board = temporaryBoard;
	++currentGeneration;
}
//Clone
std::shared_ptr<GameOfLife> ThreeStateGOL::clone() const {
	return make_shared<ThreeStateGOL>(*this);
}

//Factory
std::shared_ptr<GameOfLife> makeThreeState(int width, int height, string gameBoard) {
	return make_shared<ThreeStateGOL>(width, height, gameBoard);
}