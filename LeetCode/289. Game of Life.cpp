// 用第二位二进制来标记下一状态
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                int cnt = getLiveCount(board, i ,j);
                if(board[i][j] == 1 && (cnt == 2 || cnt == 3) || board[i][j] == 0 && cnt == 3)
                    board[i][j] |= 2;
            }
        }
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                    board[i][j] >>= 1;
            }
        }
    }

    vector<vector<int>> dir = {{1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1},{0,1},{0,-1}};

    int getLiveCount(vector<vector<int>>& board, int i, int j){
        int cnt = 0;
        for(int k = 0; k < 8; ++k){
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && (board[x][y] & 1))
                ++cnt;
        }
        return cnt;
    }
};
