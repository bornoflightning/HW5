


#pragma once

#include <string>
#include <memory>

#include "GameOfLife.h"



class BasicGOL : public GameOfLife {



public:

	BasicGOL(int width, int height, std::string gameBoard);

	void NextGen() override;

	std::shared_ptr<GameOfLife> clone() const override;
};

//Factory Function
std::shared_ptr<GameOfLife> makeStandard(int width, int height, std::string gameBoard);