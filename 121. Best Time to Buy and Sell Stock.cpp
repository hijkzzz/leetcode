class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        // 找到最大差值
        int buy = prices[0];
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
            result = max(prices[i] - buy, result);
            buy = min(prices[i], buy);
        }
        return result;
    }
};
