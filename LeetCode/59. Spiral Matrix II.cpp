class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return {};
        vector<vector<int>> result(n, vector<int>(n, 0));

        int left = 0, right = n - 1, top = 0, down = n - 1;
        int index = 1;
        while (left <= right && top <= down) {
            for (int i = left; i <= right; ++i) result[top][i] = index++;
            if (++top > down) break;
            for (int i = top; i <= down; ++i) result[i][right] = index++;
            if (--right < left) break;
            for (int i = right; i >= left; --i) result[down][i] = index++;
            if (--down < top) break;
            for (int i = down; i >= top; --i) result[i][left] = index++;
            if (++left > right) break;
        }
        return result;
    }
};
