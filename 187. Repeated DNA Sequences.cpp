class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return vector<string>();
        vector<int> alpha(26, 0);
        alpha['A' - 'A'] = 0;
        alpha['C' - 'A'] = 1;
        alpha['G' - 'A'] = 2;
        alpha['T' - 'A'] = 3;
        
        vector<string> result;
        unordered_set<int> words;
        unordered_set<int> double_words;
        for (int i = 0; i < s.size() - 9; ++i) {
            int v = 0;
            for (int j = 0; j < 10; ++j) {
                v <<= 2;
                v |= alpha[s[i + j] - 'A'];
            }
            if (!(words.insert(v)).second && (double_words.insert(v)).second)
                result.push_back(s.substr(i, 10));
        }
        return result;
    }
};