#include "game_model.h"

#include <chrono>
#include <random>

using namespace std;

void GameModel::appendToPlayBoard(const vector<char>& row)
{
    m_playBoard.push_back(row);
}

void GameModel::createFood()
{
    // 生成一个新的食物给蛇来吃
    // 随机生成一个新的位置，但是这个位置可能已经是蛇的身体了
    // 所以，需要用一个循环不断的重复在一个新生成的随机位置放置食物
    // 直到放置成功为止
    default_random_engine gen(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rowDist(0, playBoardRow() - 1);
    uniform_int_distribution<int> colDist(0, playBoardCol() - 1);

    while (true) {
        int row{ rowDist(gen) };
        int col{ colDist(gen) };

        if (canPutFoodAt(row, col))
            break;
    }
}

bool GameModel::canPutFoodAt(int row, int col)
{
    if (playBoardCell(row, col) == static_cast<char>(PlayBoardCell::Nothing)) {
        setPlayBoardCell(row, col, static_cast<char>(PlayBoardCell::Food));
        return true;
    } else {
        return false;
    }
}

bool GameModel::existFood(int row, int col) const
{
    return playBoardCell(row, col) == static_cast<char>(PlayBoardCell::Food);
}

void GameModel::eatFood(const pair<int, int>& nextPosition)
{
    setPlayBoardCell(nextPosition.first,
                     nextPosition.second,
                     static_cast<char>(PlayBoardCell::SnakeBody));

    m_snakeBody.push_front(nextPosition);
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

void GameModel::increaseSnakeBody(const pair<int, int>& nextPosition)
{
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

    return (goToRow < 0 || goToRow >= playBoardRow() || goToCol < 0 || goToCol >= playBoardCol()
            || playBoardCell(goToRow, goToCol) == static_cast<char>(PlayBoardCell::SnakeBody));
}

const vector<vector<char>>& GameModel::playBoard() const
{
    return m_playBoard;
}

{
}

const list<pair<int, int>>& GameModel::snakeBody() const
{
    return m_snakeBody;
}

{
}

{
}

char GameModel::playBoardCell(int row, int col) const
{
    return m_playBoard.at(row).at(col);
}

void GameModel::setPlayBoardCell(int row, int col, char value)
{
    m_playBoard.at(row).at(col) = value;
}
