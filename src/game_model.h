#pragma once

#include <vector>

class GameModel
{
public:
    size_t getRow() const;
    size_t getCol() const;

private:
    std::vector<std::vector<char>> m_playBoard; // 整个游戏的数据（二维数组）
};
