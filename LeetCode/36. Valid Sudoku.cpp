class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> block(9, 0);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int bit = 1 << (board[i][j] - '0');
                if ((row[i] & bit) || (col[j] & bit) || (block[i / 3 * 3 + j / 3] & bit))
                    return false;

                row[i] |= bit;
                col[j] |= bit;
                block[i / 3 * 3 + j / 3] |= bit;
            }
        }
        return true;
    }
};
