

#pragma once


#include <string>
#include <memory>

#include "GameOfLife.h"

class WrapAroundGOL : public GameOfLife {
public:
	WrapAroundGOL(int width, int height, std::string gameBoard);

	void NextGen() override;

	std::shared_ptr<GameOfLife> clone() const override;
};

std::shared_ptr<GameOfLife> makeWarpAround(int width, int height, std::string gameBoard);