#include "game_view.h"

#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

bool GameView::loadPlayDataFromFile(const string& fileName)
{
    ifstream fin{ fileName };
    if (!fin) {
        cout << "can not open file " << fileName << endl;
        return false;
    }

    return m_controller.loadPlayDataFromFile(fin);
}

void GameView::play()
{
    while (true) {
        // 系统调用：清屏
        system("clear");
        //输出游戏界面：棋盘
        printGame();

        cout << "direction: W(up) A(left) S(down) D(right)\n"
             << "$: food\n"
             << "@: snake head\n"
             << "#: snake tail\n";

        //输入一个方向，表示蛇要往这个方向前进一步
        char direction;
        cin >> direction;
        //往前走一步，如果判断无法往前走到用户指定的位置，就退出程序（比如，蛇咬到了自己、撞到了墙壁）
        if (!m_controller.goAhead(direction)) {
            cout << "Game Over!" << endl;
            break;
        }
    }
}

void GameView::printGame() const
{
    auto board{ m_controller.getPlayBoard() };
    auto body{ m_controller.getSnakeBody() };
    auto head{ body.front() };

    for (size_t row{ 0 }; row < board.size(); ++row) {
        for (size_t col{ 0 }; col < board.at(row).size(); ++col) {
            auto element{ board.at(row).at(col) };

            if (row == head.first && col == head.second) {
                cout << "@" << " ";
            } else if (element == static_cast<char>(PlayBoardCell::Food)) {
                //打印食物，内存中的 '2' 打印成 $
                cout << "$" << " ";
            } else if (element == static_cast<char>(PlayBoardCell::Nothing)) {
                //打印空白，内存中的 '0' 打印成 '_'
                cout << "_" << " ";
            } else if (element == static_cast<char>(PlayBoardCell::SnakeBody)) {
                // snake body
                cout << "#" << " ";
            } else {
                assert(false);
            }
        }

        cout << endl;
    }
}
