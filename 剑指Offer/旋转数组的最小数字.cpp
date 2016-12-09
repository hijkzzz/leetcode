class Solution {
    public:
        int minNumberInRotateArray(vector<int> rotateArray) {
            if (rotateArray.size() == 0) return -1;

            int l = 0, r = rotateArray.size() - 1;
            while (l < r) {
                // 画出三种情况的分析图
                int m = l + (r - l) / 2;
                if (rotateArray[m] < rotateArray[r]) r = m;
                else l = m + 1;
            }
            return rotateArray[l];
        }
};
