#pragma once

#include <string>

class ThreeTest {


public:

	int height{ 0 };
	int width{ 0 };
	std::string board;

	//Constructor, takes a file name for testing
	ThreeTest(const std::string& filename);

	int returnHeight() const;

	int returnWidth() const;

	std::string returnBoard() const;

}; // end class
