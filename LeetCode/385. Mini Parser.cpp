class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger *result = new NestedInteger();
        stack<NestedInteger *> st;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ',') continue;

            if (s[i] == '[') {
                st.push(new NestedInteger());
            } else if (s[i] == ']'){
                NestedInteger *temp = st.top();
                st.pop();
                if(!st.empty()) st.top()->add(*temp);
                else result = temp;
            } else {
                int j = i;
                while (j < s.size() && s[j] != ',' && s[j] != ']') ++j;
                NestedInteger *temp = new NestedInteger(stoi(s.substr(i, j - i)));

                if(!st.empty()) st.top()->add(*temp);
                else return *temp;
                // 注意 for 里面的 ++i
                i = j - 1;
            }
        }
        return *result;
    }
};
