#include "game_controller.h"

#include <cctype>
#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

bool GameController::loadPlayDataFromFile(ifstream& fin)
{
    string line;
    getline(fin, line);
    istringstream iss{ line };

    int rows{};
    int cols{};
    iss >> rows >> cols;

    for (int row{ 0 }; row < rows; ++row) {
        getline(fin, line);
        istringstream lineDataIss{ line };

        vector<char> lineData;
        char ch;
        while (lineDataIss >> ch) {
            lineData.push_back(ch);
            if (ch == static_cast<char>(PlayBoardCell::SnakeBody)) {
                m_model.increaseSnakeBody(make_pair(row, lineData.size() - 1));
            }
        }

        m_model.appendToPlayBoard(lineData);
    }

    if (getSnakeBody().empty()) {
        cout << "snake body is empty! init game failed." << endl;
        return false;
    }

    return true;
}

bool GameController::goAhead(char direction)
{
    int rowStep{ 0 };
    int colStep{ 0 };

    switch (toupper(direction)) {
    case 'W':
        rowStep = -1;
        break;
    case 'S':
        rowStep = +1;
        break;
    case 'D':
        colStep = +1;
        break;
    case 'A':
        colStep = -1;
        break;
    default:
        return true;
    }

    return goAhead(rowStep, colStep);
}

bool GameController::goAhead(int rowStep, int columnStep)
{
    auto nextPosition{ m_model.getNextPosition(rowStep, columnStep) };
    // 首先判断游戏是否已经结束
    if (m_model.isGameOver(nextPosition.first, nextPosition.second)) {
        return false;
    }
    // 判断nextPosition 处是否有食物
    // 如果有食物，就吃掉这个食物并生成一个新的食物
    if (m_model.existFood(nextPosition.first, nextPosition.second)) {
        m_model.eatFood(nextPosition);
        m_model.createFood();
    } else {
        // 如果 nextPosition 处没有食物，就移动蛇的身体
        m_model.moveTo(nextPosition);
    }

    return true;
}

const vector<vector<char>>& GameController::getPlayBoard() const
{
    return m_model.playBoard();
}

const list<pair<int, int>>& GameController::getSnakeBody() const
{
    return m_model.snakeBody();
}
