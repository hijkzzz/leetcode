class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        int m = matrix.size(), n = matrix[0].size(), i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if(matrix[i][j] == target) return true;
            // 比较每行最后一个数
            else if (matrix[i][j] < target) i++;
            // 定位具体的列
            else j--;
        }
        return false;
    }
};
