#pragma once

#include "game_model.h"

#include <fstream>

class GameController
{
public:
    bool loadPlayDataFromFile(std::ifstream& fin);

private:
    GameModel m_model;
};
