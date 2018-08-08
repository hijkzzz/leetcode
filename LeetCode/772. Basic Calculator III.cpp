class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s, i);
    }
private:
    int parseExpr(string &s, int &i) {  // parse the expression
        vector<int> nums;
        char op = '+';
        int n;
        for (; i < s.length() && op != ')'; ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == '(') {
                n = parseExpr(s, ++i);
            }
            else {
                n = parseNum(s, i);
            }
            switch(op) {
                case '+':
                    nums.push_back(n);
                    break;
                case '-':
                    nums.push_back(-n);
                    break;
                case '*':
                    nums.back() *= n;
                    break;
                case '/':
                    nums.back() /= n;
                    break;
            }
            op = s[i];
        }
        int res = 0;
        for (int n : nums) {
            res += n;
        }
        return res;
    }
    
    int parseNum(string &s, int &i) {       // parse the num
        int n = 0;
        while (i < s.length() && isdigit(s[i])) {
            n = 10 * n + s[i++] - '0';
        }
        return n;
    }
};
