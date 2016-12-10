class Solution {
    public:
        void push(int value) {
            data.push(value);
            if (data_min.empty() || data_min.top() >= value)
                data_min.push(value);
        }

        void pop() {
            if (data.top() == data_min.top())
                data_min.pop();
            data.pop();
        }

        int top() {
            return data.top();
        }

        int min() {
            return data_min.top();
        }

        stack<int> data;
        stack<int> data_min;
};
