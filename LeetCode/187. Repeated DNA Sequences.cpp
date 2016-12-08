class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return vector<string>();

        vector<char> map(256, -1);
        map['A' - 'A'] = 0;
        map['C' - 'A'] = 1;
        map['T' - 'A'] = 2;
        map['G' - 'A'] = 3;

        vector<string> result;
        unordered_map<int, int> dup;

        for (int i = 0; i < s.length() - 9; ++i) {
            int bits = 0;
            for (int j = i; j < i + 10; ++j) {
                bits <<= 2;
                bits |= map[s[j] - 'A'];
            }
            if (dup.find(bits) == dup.end()) dup[bits] = 1;
            else if (dup[bits] == 1) {
                result.push_back(s.substr(i, 10));
                dup[bits] = -1;
            }
        }
        return result;
    }
};
