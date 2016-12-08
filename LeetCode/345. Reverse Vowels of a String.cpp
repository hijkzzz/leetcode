class Solution {
public:
    string reverseVowels(string s) {
        if(s.length() < 2) return s;

        set<char> vowels({'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'});
        int l = 0, r = s.length() - 1;
        while(l < r){
            while(l < r && vowels.find(s[l]) == vowels.end()) l++;
            while(l < r && vowels.find(s[r]) == vowels.end()) r--;
            if (l < r)
                swap(s[l++],s[r--]);
        }
        return s;
    }
};
