#include "game_view.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    //创建游戏对象
    GameView snake;
    //读取文本文件，加载游戏数据
    if (!snake.loadPlayDataFromFile("data/map.txt")) {
        cout << "loadPlayDataFromFile map.txt failed!" << endl;
        return 1;
    }

    snake.play(); //整个游戏都在这个函数里

    return 0;
}
