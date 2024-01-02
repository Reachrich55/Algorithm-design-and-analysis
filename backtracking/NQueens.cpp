#include <iostream>

using namespace std;

// 打印棋盘
void printBoard(int queens[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (queens[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// 检查在当前位置放置皇后是否合法
bool isSafe(int queens[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col || abs(i - row) == abs(queens[i] - col))
            return false;
    }
    return true;
}

// 回溯算法解决N皇后问题
void solveNQueens(int queens[], int size, int row) {
    if (row == size) {
        printBoard(queens, size);
        return;
    }

    for (int col = 0; col < size; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueens(queens, size, row + 1);
        }
    }
}

int main() {
    int n = 4; // 棋盘大小
    int queens[4]; // 用于存放每行皇后所在的列

    solveNQueens(queens, n, 0);

    return 0;
}
