#pragma once

#include <list>
#include <utility>
#include <vector>

// 游戏的任意位置 只有三种情况：什么也没有；蛇的身体；食物
enum class PlayBoardCell { Nothing, SnakeBody, Food };

class GameModel
{
public:
    size_t getRow() const;
    size_t getCol() const;
    void addRow(const std::vector<char>& row);

    void move(const std::pair<int, int>& nextPosition);
private:
    char getPlayBoardCell(int row, int col) const;
    void setPlayBoardCell(int row, int col, char value);

    std::vector<std::vector<char>> m_playBoard; // 整个游戏的数据（二维数组）
    std::list<std::pair<int, int>> m_snakeBody; // 蛇的身体数据
};
