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

// 根据蛇头当前的位置，以及一个移动的向量 (rowStep,colStep)
// 得到蛇头部打算要去的新目的地的坐标
pair<int, int> GameModel::getNextPosition(int rowStep, int colStep) const
{
    auto [currentHeadRow, currentHeadCol]{ m_snakeBody.front() };

    return make_pair(currentHeadRow + rowStep, currentHeadCol + colStep);
}

//判断游戏是否已经结束了
bool GameModel::isGameOver(int goToRow, int goToCol) const
{
    // goToRow goToCol 是蛇的头打算要去的目的地
    // 这个目的地会导致gomeover
    // 比如超出了游戏界面（下标越界）
    // 比如撞到了蛇的身体

    return (goToRow < 0 || goToRow >= getRow() || goToCol < 0 || goToCol >= getCol()
            || getPlayBoardCell(goToRow, goToCol) == static_cast<char>(PlayBoardCell::SnakeBody));
}

char GameModel::getPlayBoardCell(int row, int col) const
{
    return m_playBoard.at(row).at(col);
}

void GameModel::setPlayBoardCell(int row, int col, char value)
{
    m_playBoard.at(row).at(col) = value;
}
