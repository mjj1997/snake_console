#include "game_view.h"

#include <fstream>
#include <iostream>

bool GameView::loadPlayDataFromFile(const std::string& fileName)
{
    std::ifstream fin{ fileName };
    if (!fin) {
        std::cout << "can not open file " << fileName << std::endl;
        return false;
    }

    return m_controller.loadPlayDataFromFile(fin);
}
