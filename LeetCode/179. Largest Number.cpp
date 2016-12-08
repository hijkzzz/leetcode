class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            vector<string> strs;
            for (auto n : nums) strs.push_back(to_string(n));

            sort(strs.begin(), strs.end(), [](string &s1, string &s2){ return s1 + s2 > s2 + s1; });
            string res =  accumulate(strs.begin(), strs.end(), string(""));
            while (res[0] == '0' && res.size() > 1) {
                res.erase(0, 1);
            }
            return res;
        }
};
