#include <iostream>
#include <vector>

int main() {
    int rows = 24;
    int cols = 80;


    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
    matrix[11][3] = 2027;

    int i = 11 * 80 + 3;

    for(auto &row : matrix) {
        for(auto &val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}