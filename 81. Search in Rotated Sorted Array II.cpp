// Yes, when there could be duplicates in the array, the worst case is O(n).
//
// To explain why, consider this sorted array 1111115, which is rotated to 1151111.
//
// Assume left = 0 and mid = 3, and the target we want to search for is 5. Therefore, the condition A[left] == A[mid] holds true, which leaves us with only two possibilities:
//
// All numbers between A[left] and A[right] are all 1's.
// Different numbers (including our target) may exist between A[left] and A[right].
// As we cannot determine which of the above is true, the best we can do is to move left one step to the right and repeat the process again. Therefore, we are able to construct a worst case input which runs in O(n), for example: the input 11111111...115.
//
// Below is a pretty concise code (thanks to bridger) for your reference which I found from the old discuss.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return true;
            // m 在左半部分
            if (nums[m] > nums[l]) {
                // target 在 l, m 之间
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m +  1;
            // m 在右半部分
            } else if (nums[m] < nums[l]){
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            // 相等时无法判断 m 在哪一半
            } else {
                ++l;
            }
        }
        return false;
    }
};
