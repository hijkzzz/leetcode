class Solution {
    public:
        //自下而上动态规划
        int minimumTotal(vector<vector<int>>& triangle) {
            for (int i = triangle.size() - 2; i >= 0; --i ) {
                for (int j = 0; j < triangle[i].size(); ++j) {
                    //要么取左边要么取右边
                    triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                }
            }

            return triangle[0][0];
        }
};
