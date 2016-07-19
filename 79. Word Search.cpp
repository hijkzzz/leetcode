class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            if (word.size() == 0) return false;

            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    if (helper(word, 0, board, i, j))
                        return true;
                }
            }
            return false;
        }

        bool helper(const string &word, int k, vector<vector<char>>& board, int i, int j) {
            if (k == word.size()) return true;
            if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) return false;
            if (board[i][j] != word[k]) return false;

            // 标记已经访问过
            board[i][j] |= 128;
            bool flag = helper(word, k + 1, board, i, j + 1)
                || helper(word, k + 1, board, i, j - 1)
                || helper(word, k + 1, board, i + 1, j)
                || helper(word, k + 1, board, i - 1, j);
            board[i][j] &= 127;         
            return flag;
        }
};
