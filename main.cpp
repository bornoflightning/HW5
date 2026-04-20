
/*
Victor Escarcega
CT301 Spring Semester

*/



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "GameOfLife.h"
#include "BasicGOL.h"
#include "TestingHelper.h"
#include "ThreeStateGOL.h"


using namespace std;


int main(int argc, char* argv[]) {



	//argc tells us how many arguments exist
	//argv tells us the actual values
	//GOLAP is argv[0]
	//argv[1] is the file name, we check to make sure there is a file name

	//Here we make sure that there is a file name by counting the number of arguments
	if (argc < 2) {
		cerr << "Error: Please provide an input file name. \n";
		return 1;
	} // end if that checks for input 

	//defaults to generation and print intervals
	int intTotalGenerations = 10;
	int intPrintIntervals = 1;

	//checks for 3 arguments
	// we use stoi(string to integer) to convert char into int for index on string arguments
	if (argc == 3) {
		intTotalGenerations = stoi(argv[2]);
	}

	//checks for 4 arguments
	if (argc == 4) {
		intTotalGenerations = stoi(argv[2]);
		intPrintIntervals = stoi(argv[3]);
	}

	//Testing
	TestingHelper parser(argv[1]);

	int height = parser.returnHeight();
	int width = parser.returnWidth();
	string board = parser.returnBoard();

	BasicGOL original(width, height, board);

	cout << "Orginal Before clone" << endl;
	original.PrintGame();
	cout << "\n";

	auto clonedGame = original.clone();

	cout << "Clone right after clone():\n";
	clonedGame->PrintGame();
	cout << "\n";

	//Here we advance the clone for testing
	clonedGame->NextGen();

	cout << "Original after clone advanced: \n";
	original.PrintGame();
	cout << "\n";

	cout << "Clone after using NextGen(): \n";
	clonedGame->PrintGame();
	cout << endl;


	cout << "Begin Three State Test" << endl;

	ThreeStateGOL test(width, height, board);

	cout << "Initial board: \n";
	test.PrintGame();
	cout << endl;

	auto clone = test.clone();

	clone->NextGen();

	cout << "Original after clone on Three State test" << endl;
	test.PrintGame();

	cout << "Clone after Next:\n";
	clone->PrintGame();

	



	//GameOfLife Game(argv[1]);
	//Game.PrintGame();
	//cout << "\n";

	//for (int intCurrentGeneration = 1; intCurrentGeneration <= intTotalGenerations; ++intCurrentGeneration) {
	//	Game.NextGen();

	//	//match the print invterval
	//	if (intCurrentGeneration % intPrintIntervals == 0) {
	//		Game.PrintGame();
	//		cout << "\n";
	//	}
	//}


return 0;
}