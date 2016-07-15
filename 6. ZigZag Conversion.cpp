class Solution {
    public:
        string convert(string s, int numRows) {
            if(s == "" || numRows == 1) return s;

            vector<string> result(numRows, "");
            int i = 0, j = -1;
            while(i < s.size()){
                while(j <= numRows - 2 && i < s.size())
                    result[++j].append(1, s[i++]);
                while(j >= 1 && i < s.size())
                    result[--j].append(1, s[i++]);
            }
            return accumulate(result.begin(), result.end(), string(""));
        }
};
