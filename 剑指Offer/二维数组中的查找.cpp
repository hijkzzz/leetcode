/* 
 * 矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
 * 因此从左下角开始查找，当要查找数字比左下角数字大时。右移
 * 要查找数字比左下角数字小时，上移
 */
class Solution {
    public:
        bool Find(int target, vector<vector<int> > array) {
            if (!array.size() || !array[0].size()) return false;

            int m = array.size();
            int n = array[0].size();

            for (int i = m - 1, j = 0; i >= 0 && j < n;) {
                if (array[i][j] == target) return true;
                if (array[i][j] < target) j++;
                else i--;
            }
            return false;
        }
};
