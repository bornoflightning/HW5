
#pragma once

#include <string>
#include <vector>
#include <memory>


class GameOfLife {
protected:
	//board dimensions
	
	int height{ 0 };
	int	width{ 0 };
	int currentGeneration{ 0 };

	//1D board
	
	std::vector<int> board;

	//Helpers
	//helper lets us keep track of live neighbors with standard bounds
	int countLiveNeighbors(int row, int col) const;

public:

	virtual ~GameOfLife() = default;

	//CONSTRUCTOR
	//A constructor that takes the int width, int height, and a game string (a 1D representation of the grid).

	GameOfLife(int width, int height, const std::string& gameString);

	GameOfLife(const GameOfLife&) = default;

	GameOfLife& operator=(const GameOfLife&) = default;

	GameOfLife& operator+=(int gens);

	GameOfLife& operator++();

	std::shared_ptr<GameOfLife> operator+(int gens) const;

	virtual void NextGen() = 0;

	// A member function nextNGen(int) that takes an int and advances the current board by that many generations.
	//Homework description: Advances the game by "gens" generations. Throws invalid_argument error if passed a negative value.
	virtual void NextNGen(int n);


	//A member function printGame() that formats and prints the game to standard output. 
	//Homework description: Prints the current number of generations and gameboard to cout. 
	// See HW2 instructions for specifics on output format.
	virtual void PrintGame() const;

	//Throws out_of_range error if index is out of bounds. 
	// This method sets a live_cell at the index to a dead_cell and vice versa.
	virtual void ToggleCell(int index);

	//Same as ToggleCell(index).It throws a out_of_range error if either row or column are out of bounds.
	virtual void ToggleCell(int row, int col);

	virtual std::shared_ptr<GameOfLife> clone() const = 0;


	


};