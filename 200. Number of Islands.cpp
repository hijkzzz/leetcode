class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            if(grid.size() == 0 || grid[0].size() == 0)
                return 0;

            int res = 0;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if(grid[i][j] == '1'){
                        res++;
                        fill(grid, i, j);
                    }
                }
            }

            return res;
        }

        void fill(vector<vector<char>> &grid, int i, int j) {
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            grid[i][j] = '0';

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                //上，下，左，右
                //必须先清零，再推进队列，否则可能重复处理
                if(x > 0 && grid[x - 1][y] == '1'){
                    q.push(make_pair(x - 1, y));
                    grid[x - 1][y] = '0';
                }
                if(x + 1 < grid.size() && grid[x + 1][y] == '1'){
                    q.push(make_pair(x + 1, y));
                    grid[x + 1][y] = '0';
                }
                if(y > 0 && grid[x][y - 1] == '1'){
                    q.push(make_pair(x, y - 1));
                    grid[x][y - 1] = '0';
                }
                if(y + 1 < grid[0].size() && grid[x][y + 1] == '1'){
                    q.push(make_pair(x, y + 1));
                    grid[x][y + 1] = '0';
                }
            }
        }
};
