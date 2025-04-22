#pragma once

#include "game_model.h"

#include <fstream>

class GameController
{
public:
    bool loadPlayDataFromFile(std::ifstream& fin);

    bool goAhead(char direction);
    bool goAhead(int rowStep, int columnStep);

private:
    GameModel m_model;
};
