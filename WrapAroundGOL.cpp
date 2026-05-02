#include "WrapAroundGOL.h"

#include <vector>
#include <stdexcept>
#include <memory>

using namespace std;

WrapAroundGOL::WrapAroundGOL(int width, int height, std::string gameBoard)
	: GameOfLife(width, height, gameBoard)
{

}

//Wrap Around rules for standard game 
void WrapAroundGOL::NextGen() {
	vector<int> temporaryBoard(width * height);

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            int liveNeighbors = 0;

            //nested loop, checks coordinates and counts live neighbors
            for (int deltaRow = -1; deltaRow <= 1; ++deltaRow) {
                for (int deltaCol = -1; deltaCol <= 1; ++deltaCol) {
                    if (deltaRow == 0 && deltaCol == 0) {
                        continue;
                    }

                    int neighborRow = (row + deltaRow + height) % height;
                    int neighborCol = (col + deltaCol + width) % width;

                    int neighborIndex = neighborRow * width + neighborCol;
                    if (board[neighborIndex] == 1) {
                        ++liveNeighbors;
                    }
                }
            } // end count of live neighbors

            int index = row * width + col;
            int current = board[index];
            int nextValue = 0;

            if (current == 1) {
                if (liveNeighbors == 2 || liveNeighbors == 3) {
                    nextValue = 1;
                }
                else {
                    nextValue = 0;
                }
            }
            else {
                if (liveNeighbors == 3) {
                    nextValue = 1;
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
shared_ptr<GameOfLife> WrapAroundGOL::clone() const{
    return make_shared <WrapAroundGOL>(*this);
}

//Factory
shared_ptr<GameOfLife> makeWrapAround(int width, int height, std::string gameBoard) {
    return make_shared<WrapAroundGOL>(width, height, gameBoard);
}