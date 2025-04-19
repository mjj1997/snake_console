#include "game_view.h"

#include <fstream>
#include <iostream>

bool GameView::loadPlayDataFromFile(const std::string& fileName)
{
    std::ifstream fin{ fileName };
    if (!fin) {
        std::cout << "can not open file " << fileName << std::endl;
        return false;
    }

    return m_controller.loadPlayDataFromFile(fin);
}

void GameView::play()
{
    while (true) {
        // 系统调用：清屏
        system("cls");
        //输出游戏界面：棋盘
        printMatrix();

        std::cout << "direction: W(up) A(left) S(down) D(right)\n"
                  << "$: food\n"
                  << "@: snake head\n"
                  << "#: snake tail\n";

        //输入一个方向，表示蛇要往这个方向前进一步
        char direction;
        std::cin >> direction;
        //往前走一步，如果判断无法往前走到用户指定的位置，就退出程序（比如，蛇咬到了自己、撞到了墙壁）
        if (!m_controller.goAhead(direction)) {
            std::cout << "Game Over!" << std::endl;
            break;
        }
    }
}

// TODO: complete this function
void GameView::printMatrix() const
{
}
