#pragma once

#include <string>

class TestingHelper {
	

public:

	int height{ 0 };
	int width{ 0 };
	std::string board;

	//Constructor, takes a file name for testing
	TestingHelper(const std::string& filename);

	int returnHeight() const;

	int returnWidth() const;

	std::string returnBoard() const;

}; // end class
