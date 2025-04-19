#pragma once

#include "game_controller.h"

#include <string>

class GameView
{
public:
    // 从文件中加载界面数据，存放到内部容器中，再根据容器内容绘制界面
    bool loadPlayDataFromFile(const std::string& fileName);

private:
    GameController m_controller;
};
