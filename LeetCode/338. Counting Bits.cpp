/*
 *     0
 *     1
 *    10
 *    11
 *   100
 *   101
 *   110
 *   111
 *   发现规律了吧
 */
class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return {0};
        vector<int> result({0, 1});

        while(result.size() < num + 1) {
            int k = result.size();
            for (int i = 0; i < k; ++i) {
                result.push_back(result[i] + 1);
                if (result.size() == num + 1) break;
            }
        }
        return result;
    }
};
