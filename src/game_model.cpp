#include "game_model.h"

size_t GameModel::getRow() const
{
    return m_playBoard.size();
}

size_t GameModel::getCol() const
{
    return m_playBoard.at(0).size();
}

