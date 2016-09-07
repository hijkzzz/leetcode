/*
 *  题意即从 magazine 中取出字母，判断能否组成 ransomNote
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> alphas(26, 0);
        for (auto &c : magazine) {
            ++alphas[c - 'a'];
        }
        for (auto &c : ransomNote) {
            if (alphas[c - 'a'] > 0)
                --alphas[c - 'a'];
            else
                return false;
        }
        return true;
    }
};
