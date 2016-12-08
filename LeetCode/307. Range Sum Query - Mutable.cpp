// Binary index tree
// http://dongxicheng.org/structure/binary_indexed_tree/
class NumArray {
public:
    NumArray(vector<int> &nums) 
        : nums2(nums), size(nums.size()), bit(vector<int>(size + 1, 0)) {
        
        for (int i = 0; i < size; ++i) {
            plus(i + 1, nums2[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - nums2[i];
        plus(i + 1, diff);
        nums2[i] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
private:
    vector<int> nums2;
    int size;
    vector<int> bit;
    
    int lowbit (int x) {
        return x & (x ^ (x - 1));
    }
    
    void plus(int pos, int diff) {
        while (pos <= size) {
            bit[pos] += diff;
            pos += lowbit(pos);
        }
    }
    
    int getSum(int end) {
        int sum = 0;
        while (end > 0) {
            sum += bit[end];
            end -= lowbit(end);
        }
        return sum;
    }
};