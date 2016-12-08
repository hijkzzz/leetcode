class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) return 0;
        
        int result = 0;
        int num = 0;
        int sign = 1;
        stack<int> st;
        
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                num = 10 * num + (s[i] - '0');
            } else if (s[i] == '+') {
                result += sign * num;
                sign = 1;
                num = 0;
            } else if (s[i] == '-') {
                result += sign * num;
                sign = -1;
                num = 0;
            } else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                sign = 1;
                result = 0;
            } else if (s[i] == ')') {
                result += sign * num; 
                num = 0;
                // 与前一项合并
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        
        // 最后一个数字
        if(num != 0) result += sign * num;
        return result; 
    }
};