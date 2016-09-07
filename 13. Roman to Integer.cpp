class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> c2i = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int last = 0;
        for (int i = 0; i < s.size(); ++i) {
            int current = c2i[s[i]];
            if (current > last) {
                result -= 2 * last;
            }
            result += current;
            last = current;
        }
        return result;
    }
};
