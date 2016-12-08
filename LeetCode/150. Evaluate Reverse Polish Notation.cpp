class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> s;

            for (auto &temp : tokens) {
                if (temp == "*" || temp == "/" || temp == "+" || temp == "-")
                    s.push(compute(temp, s));
                else
                    s.push(stol(temp));
            }

            return s.top();
        }

        int compute(const string &op, stack<int> &s) {
            int a = s.top();
            s.pop();
            int b=  s.top();
            s.pop();

            if (op == "*") return b * a;
            else if (op == "/") return b / a;
            else if (op == "+") return b + a;
            else return b - a;
        }
};
