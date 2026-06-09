#include "leet.h"

class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, n);
        return result;
    }
    void backtrack(vector<string>& board, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (validQueen(board, row, i)) {
                board[row][i] = 'Q';
                backtrack(board, row+1, n);
                board[row][i] = '.';
            }
        }
    }
    bool validQueen(vector<string>& board, int row, int col) {
        // check col
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q' && i != row) {
                return false;
            }
        }
        // check diag
        int i = row - 1;
        int j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }
        i = row - 1;
        j = col + 1;
        while (i < board.size() && j < board.size()) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
};
