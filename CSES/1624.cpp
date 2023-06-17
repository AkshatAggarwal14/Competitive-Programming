#include <bits/stdc++.h>
using namespace std;

char board[8][8];
int ways = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i <= row; ++i) {
        if (board[i][col] == 'Q') return false;
        if (min(row, col) >= i && board[row - i][col - i] == 'Q') return false;
        if (row - i >= 0 && col + i < 8 && board[row - i][col + i] == 'Q') return false;
    }
    return true;
}

void solve(int row = 0) {
    if (row == 8) {
        ++ways;  // at end add ans
        return;
    }
    for (int col = 0; col < 8; ++col) {
        if (isSafe(row, col)) {  // only place queens at safe position
            if (board[row][col] != '*') {
                board[row][col] = 'Q';
                solve(row + 1);
                board[row][col] = '.';  // backtrack}
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> board[i][j];
        }
    }
    solve();
    cout << ways << '\n';
}