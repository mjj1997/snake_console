#include "game_model.h"

using namespace std;

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

void GameModel::move(const pair<int, int>& nextPosition)
{
    auto tail{ m_snakeBody.back() };

    // 删除尾巴
    setPlayBoardCell(tail.first, tail.second, static_cast<char>(PlayBoardCell::Nothing));
    m_snakeBody.pop_back();

    setPlayBoardCell(nextPosition.first,
                     nextPosition.second,
                     static_cast<char>(PlayBoardCell::SnakeBody));
    m_snakeBody.push_front(nextPosition);
}

char GameModel::getPlayBoardCell(int row, int col) const
{
    return m_playBoard.at(row).at(col);
}

void GameModel::setPlayBoardCell(int row, int col, char value)
{
    m_playBoard.at(row).at(col) = value;
}
