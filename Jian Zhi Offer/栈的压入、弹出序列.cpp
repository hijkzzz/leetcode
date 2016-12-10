class Solution {
    public:
        // 模拟压栈，弹出
        bool IsPopOrder(vector<int> pushV,vector<int> popV) {
            if(pushV.size() == 0) return false;
            stack<int> s;
            for(int i = 0, j = 0;i < pushV.size();){
                s.push(pushV[i++]);
                while(!s.empty() && s.top() == popV[j]){
                    s.pop();
                    j++;
                }      
            }
            return s.empty();
        }
};
