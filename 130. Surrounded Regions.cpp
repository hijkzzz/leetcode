/*
 * First, check the four border of the matrix. If there is a element is
 * 'O', alter it and all its neighbor 'O' elements to '1'.
 * Then ,alter all the 'O' to 'X'
 * At last,alter all the '1' to 'O'
 */
class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            if(!board.size() || !board[0].size()) return;
            int row = board.size();
            int col = board[0].size();

            // 检查边界，并且把 0 及其相邻的 0 都填为 1，这些元素无法被 1 围住
            for (int j = 0; j < col; ++j) {
                check(0, j, board);
                check(row - 1, j, board);
            }

            for (int i = 1; i < row - 1; ++i) {
                check(i, 0, board);
                check(i, col - 1, board);
            }

            // 填写 O 为 X
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (board[i][j] == 'O') board[i][j] = 'X';
                }
            }

            // 填写 1 为 O
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (board[i][j] == '1') board[i][j] = 'O';
                }
            }
        }

        void check(int i, int j, vector<vector<char>>& board) {
            if (board[i][j] == 'O') {
                int row = board.size();
                int col = board[0].size();

                board[i][j] = '1';
                // 递归检查相邻坐标
                if(i > 1) check(i - 1, j, board);
                if(i < row - 2) check(i + 1, j, board);
                if(j > 1) check(i, j - 1, board);
                if(j < col - 2) check(i, j + 1, board);
            }
        }
};
