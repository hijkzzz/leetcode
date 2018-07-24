class Solution
{
    public:
        void push(int node) {
            in.push(node);
        }

        int pop() {
            if (out.empty()) {
                while (!in.empty()) {
                    out.push(in.top());
                    in.pop();
                }
            }

            int temp = out.top();
            out.pop();
            return temp;
        }

    private:
        stack<int> in;
        stack<int> out;
};
