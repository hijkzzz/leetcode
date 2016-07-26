class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, int> str2i;
            vector<vector<string>> res;

            for (int i = 0; i < strs.size(); i++) {
                string temp = strs[i];
                sort(temp.begin(), temp.end());
                auto iter = str2i.find(temp);

                if (iter != str2i.end()) {
                    res[iter->second].push_back(strs[i]);
                } else {
                    res.push_back(vector<string>(1, strs[i]));
                    str2i[temp] = res.size() - 1;
                }
            }

            return res;
        }
};
