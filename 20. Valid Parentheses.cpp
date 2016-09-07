class Solution {
public:
    bool isMatch(char a, char b){
        if(a == '(' && b == ')'
        || a == '[' && b == ']'
        || a == '{' && b == '}')
            return true;
        else
            return false;
    }

    bool isValid(string s) {
        int length = s.length();
        if(length == 0 || (length & 1)) return false;

        stack<char> st;
        for(int i = 0; i < length; i++){
            if(s[i] == '(' || s[i] == '{' ||s[i] == '[')
                st.push(s[i]);
            //如果是右括号
            //栈内没有左括号 或者左括号不匹配
            else if(st.empty() || !isMatch(st.top(), s[i]))
                return false;
            else
                st.pop();
        }
        return st.empty();
    }
};
