class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        for (; j < t.size(); ++j) {
            if (t[j] == s[i]) ++i;
            if (i == s.size()) break;
        }
        return i == s.size();
    }
};
