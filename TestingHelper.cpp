


#include <string>
#include <fstream>
#include <stdexcept>

#include "TestingHelper.h"

using namespace std;

TestingHelper::TestingHelper(const string& filename) {
	//I will have good control over the files, so likely, there will be no throws here
	// files for testing. 
	//
	ifstream input(filename);


	
	input >> height >> width;


	char character;
	while (input >> character) {
		if (character == 'X') {
			board.push_back('X');
		}
		else if (character == 'O') {
			board.push_back('O');
		}
		else{
			throw invalid_argument("Invalid character in board!");
		}
	}
} // end constructor

int TestingHelper::returnHeight() const {
	return height;
}

int TestingHelper::returnWidth() const {
	return width;
}

string TestingHelper::returnBoard() const {
	return board;
}

