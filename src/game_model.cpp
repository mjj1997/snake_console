#include "game_model.h"

size_t GameModel::getRow() const
{
    return m_playBoard.size();
}

size_t GameModel::getCol() const
{
    return m_playBoard.at(0).size();
}

void GameModel::addRow(const vector<char>& row)
{
    m_playBoard.push_back(row);
}

char GameModel::getPlayBoardCell(int row, int col) const
{
    return m_playBoard.at(row).at(col);
}
