/*
 *  对数组排序即可
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 ) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];

        int length = min(first.size(), last.size());
        for(int i = 0; i < length; i++){
            if(first[i] != last[i]) return first.substr(0, i);
        }

        return first;
    }
};
