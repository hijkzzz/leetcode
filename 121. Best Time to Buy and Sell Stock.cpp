class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if(prices.size() < 2) return 0;
       //寻找最大差值
       int max_profit = 0;
       int buy = prices[0];
       for(int i = 1; i < prices.size(); i++){
            int diff = prices[i] - buy;
            if(diff > max_profit){
                max_profit = diff;
            }
            if(buy > prices[i]){
                buy = prices[i];
            }
       }
       return max_profit;
    }
};
