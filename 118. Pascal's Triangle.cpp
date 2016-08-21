class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        if (numRows == 0) return pt;

        pt.push_back(vector<int>{1});
        for (int i = 2; i <= numRows; ++i) {
            vector<int> current(i, 0);
            for (int j = 0; j < i; ++j) {
                if (j == 0 || j == i - 1) current[j] = 1;
                else current[j] = pt[i - 2][j - 1] + pt[i - 2][j];
            }
            pt.push_back(current);
        }
        return pt;
    }
};
