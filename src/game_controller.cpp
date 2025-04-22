#include "game_controller.h"

using namespace std;

bool GameController::loadPlayDataFromFile(ifstream& fin)
{
    std::string line;
    std::getline(fin, line);
    std::istringstream iss{ line };

    int rows{};
    int cols{};
    iss >> rows >> cols;

    for (int row{ 0 }; row < rows; ++row) {
        std::getline(fin, line);
        std::istringstream lineDataIss{ line };

        std::vector<char> lineData;
        char ch;
        while (lineDataIss >> ch) {
            lineData.push_back(ch);
            if (ch == static_cast<char>(PlayBoardCell::SnakeBody)) {
                m_model.increaseBody(make_pair(row, lineData.size() - 1));
            }
        }

        m_model.addRow(lineData);
    }

    if (m_model.getSnakeBody().empty()) {
        cout << "snake body is empty! init game failed." << endl;
        return false;
    }

    return true;
}

