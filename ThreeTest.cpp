


#include <string>
#include <fstream>
#include <stdexcept>

#include "ThreeTest.h"

using namespace std;

ThreeTest::ThreeTest(const string& filename) {
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
		else {
			board.push_back('D');
		}
	}
} // end constructor

int ThreeTest::returnHeight() const {
	return height;
}

int ThreeTest::returnWidth() const {
	return width;
}

string ThreeTest::returnBoard() const {
	return board;
}

