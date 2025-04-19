#pragma once

#include "game_controller.h"

#include <string>

class GameView
{
public:
    // 从文件中加载界面数据，存放到内部容器中，再根据容器内容绘制界面
    bool loadPlayDataFromFile(const std::string& fileName);
    // 开始游戏
    void play();

private:
    // 打印贪吃蛇游戏，将界面和内存之间的数据对应起来
    // 界面     内存
    // '_'  <== '0'
    // '$'  <== '2'
    // '#'  <== '1'
    // '@'  <== '1'
    void printMatrix() const;

private:
    GameController m_controller;
};
