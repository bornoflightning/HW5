#pragma once

#include <string>
#include <memory>

#include "GameOfLife.h"

class ThreeStateGOL : public GameOfLife {
public:
	ThreeStateGOL(int width, int height, std::string gameBoard);

	void NextGen() override;

	std::shared_ptr<GameOfLife> clone() const override;
};

//Factory Function 
std::shared_ptr<GameOfLife> makeThreeState(int width, int height, std::string gameBoard);