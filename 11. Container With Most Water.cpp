class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int container = INT_MIN;

        while (l < r) {
            int h = min(height[l], height[r]);
            container = max(container, h * (r - l));
            // 长度变小，只能增加高度，容量才能提升
            while (height[l] <= h && l < r) l++;
            while (height[r] <= h && l < r) r--;
        }
        return container;
    }
};
