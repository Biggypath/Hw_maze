#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>


using namespace std;

class Maze {
private:
    // 0 is space
    // 1 is path
    // 2 is maze
    array<array<int, 15>, 15> maze = {};

public:
    Maze(array<array<int, 15>, 15> amaze) : maze(amaze) {}

    void gen_path() {
        for (int row = 0; row < 15; row++) {
            if (row % 2 == 0) {
                int col = 1 + rand() % 13;
                maze[row][col] = 1;
                if (row != 14) {
                    maze[row + 1][col] = 1;
                } 
                if (row != 0) {
                    maze[row - 1][col] = 1;
                }
            }
        }

        for (int row = 1; row < 14; row += 2) {
            vector<int> begintoend;
            for (int col = 0; col < 15; col++) {
                if (maze[row][col] == 1) {
                    begintoend.push_back(col);
                }
            }
            for (int begin = begintoend[0] + 1; begin < begintoend[1]; begin++) {
                maze[row][begin] = 1;
            }
        }
    }

    void gen_maze() {
        for (int row = 0; row < 15; row++) {
            for (int col = 0; col < 15; col++) {
                if ((row == 0 || row == 14 || col == 0 || col == 14) && maze[row][col] != 1) {
                    maze[row][col] = 2;
                }
            }

            int quan = 1 + rand() % 14;
            for (int j = 0; j < quan; j++) {
                int col2 = 1 + rand() % 14;
                if (maze[row][col2] != 1) {
                    maze[row][col2] = 2;
                }
            }
            
        }
    }

    void print_maze() {
        for (int row = 0; row < 15; row++) {
            for (int col = 0; col < 15; col++) {
                switch (maze[row][col]) {
                case 0:
                    cout << " ";
                    break;

                case 1:
                    cout << ".";
                    break;

                case 2:
                    cout << "#";
                    break;

                default:
                    break;
                }
            }
            cout << endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    array<array<int, 15>, 15> map = {};
    Maze maze = Maze(map);
    maze.gen_path();
    maze.gen_maze();
    maze.print_maze();
}
