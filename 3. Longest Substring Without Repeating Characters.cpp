class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxx = 0;
        int i = 0, j = 0;
        unordered_set<char> dup;

        while (j < s.length()) {
            if (dup.find(s[j]) == dup.end()) {
                dup.insert(s[j++]);
                maxx = max(maxx, (int)dup.size());
            // 如果出现重复，移动头指针
            } else {
                dup.erase(s[i++]);
            }
        }
        return maxx;
    }
};
