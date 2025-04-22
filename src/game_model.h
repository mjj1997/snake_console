#pragma once

#include <list>
#include <utility>
#include <vector>

// 游戏的任意位置 只有三种情况：什么也没有；蛇的身体；食物
enum class PlayBoardCell { Nothing = '0', SnakeBody = '1', Food = '2' };

class GameModel
{
public:
    const std::vector<std::vector<char>>& playBoard() const;
    void appendToPlayBoard(const std::vector<char>& row);
    const std::list<std::pair<int, int>>& snakeBody() const;
    void increaseSnakeBody(const std::pair<int, int>& nextPosition);

    // 计算蛇的头要去的新坐标
    std::pair<int, int> getNextPosition(int rowStep, int colStep) const;
    //撞到墙壁或者蛇自己的身体就结束游戏
    bool isGameOver(int goToRow, int goToCol) const;
    bool existFood(int row, int col) const;
    void eatFood(const std::pair<int, int>& nextPosition);
    void createFood();
    void moveTo(const std::pair<int, int>& nextPosition);

private:
    char playBoardCell(int row, int col) const;
    void setPlayBoardCell(int row, int col, char value);

    std::vector<std::vector<char>> m_playBoard; // 整个游戏的数据（二维数组）
    std::list<std::pair<int, int>> m_snakeBody; // 蛇的身体数据
};
