class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (num[mid] > num[hi]) // m 在较高的部分
                lo = mid + 1;            
            else if (num[mid] < num[hi]) // m 在较低的部分
                hi = mid;            
            else  // When num[mid] == num[hi], we couldn't sure the position of minimum in mid's left or right, so just let upper bound reduce one.
                hi--;       
            
        }
        return num[lo];
    }
};