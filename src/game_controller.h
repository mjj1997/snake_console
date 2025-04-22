#pragma once

#include "game_model.h"

#include <fstream>

class GameController
{
public:
    bool loadPlayDataFromFile(std::ifstream& fin);

    bool goAhead(char direction);
    bool goAhead(int rowStep, int columnStep);

    const std::vector<std::vector<char>>& getPlayBoard() const;
    const std::pair<int, int>& getSnakeHead() const;
    const std::list<std::pair<int, int>>& getSnakeBody() const;

private:
    GameModel m_model;
};
