#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // int totalNQueens(int n, int row = 0, int col = 0, int diag = 0, int anti_diag = 0) {
    //     if (row == n) return 1;
    //     int count = 0;
    //     for (int column = 0; column < n; column++) {
    //         int col_mask = 1 << column,
    //             diag_mask = 1 << (row + column),
    //             anti_diag_mask = 1 << (row - column + n - 1);
    //         if (!(col & col_mask) && !(diag & diag_mask) && !(anti_diag & anti_diag_mask))
    //             count += totalNQueens(n, row + 1, col | col_mask, diag | diag_mask,
    //                                   anti_diag | anti_diag_mask);
    //     }
    //     return count;
    // }
    // we need to place one queen in each row
    vector<vector<string>> ans;
    vector<string> board;
    int num;
    int totalNQueens(int n) {
        board.resize(n, string(n, '.'));
        num = n;
        backtrack();
        return ans.size();
    }
    // checks if a cell is safe
    // check only diagonals, rows for queen in previous rows
    bool isSafe(int row, int col) {
        for (int i = 0; i <= row; ++i) {
            if (board[i][col] == 'Q') return false;
            if (min(row, col) >= i && board[row - i][col - i] == 'Q') return false;
            if (row - i >= 0 && col + i < num && board[row - i][col + i] == 'Q') return false;
        }
        return true;
    }
    void backtrack(int row = 0) {
        if (row == num) {
            ans.push_back(board);  // at end add board to ans
            return;
        }
        for (int col = 0; col < num; ++col) {
            if (isSafe(row, col)) {  // only place queens at safe position
                board[row][col] = 'Q';
                backtrack(row + 1);
                board[row][col] = '.';  // backtrack
            }
        }
    }
};
