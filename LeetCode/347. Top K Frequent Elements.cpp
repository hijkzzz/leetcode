class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto &num : nums)
            ++count[num];
        // 桶排序
        for (const auto &pair : count)
            bucket[pair.second].push_back(pair.first);

        vector<int> result;
        for (int i = bucket.size() - 1; i > 0 && k; --i)
            while (k && bucket[i].size() > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        return result;
    }
};
