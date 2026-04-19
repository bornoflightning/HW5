


#pragma once

#include <string>
#include "GameOfLife.h"
#include <memory>



class BasicGOL : public GameOfLife {
private:


public:

	BasicGOL(int width, int height, std::string gameBoard);

	void NextGen() override;

	std::shared_ptr<GameOfLife> clone() const override;
};

//Factory Function
std::shared_ptr<GameOfLife> makeStandard(int width, int height, std::string gameBoard);