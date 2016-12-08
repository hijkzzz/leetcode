class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
            if(!matrix.size() || !matrix[0].size()) return result;

            int top = 0, left = 0, down = matrix.size() - 1, right = matrix[0].size() - 1;
            while(left <= right && top <= down) {
                for (int i = left; i <= right; ++i) result.push_back(matrix[top][i]);
                // 如果没有元素了直接结束
                if(++top > down) break;
                for (int j = top; j <= down; ++j) result.push_back(matrix[j][right]);
                if(--right < left) break;
                for (int i = right; i >= left; --i) result.push_back(matrix[down][i]);
                if(--down < top) break;
                for (int j = down; j >= top; --j) result.push_back(matrix[j][left]);
                if(++left > right) break;
            }
            return result;
        }
};
