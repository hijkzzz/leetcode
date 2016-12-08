class Solution {
public:
    vector<int> getNext(string needle) {
        vector<int> next(needle.size(), 0);
        //上一次的 next 值
        int k = 0;
        for (int i = 1; i < needle.size(); ++i) {
            while (needle[i] != needle[k] && k != 0) k = next[k - 1];
            if (needle[i] == needle[k]) k++;
            next[i] = k;
        }
        return next;
    }

    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "") return -1;
        vector<int> next = getNext(needle);

        // needle 的指针
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            while(needle[j] != haystack[i] && j != 0) j = next[j - 1];
            if (needle[j] == haystack[i]) j++;
            if (j == needle.size()) return i - needle.size() + 1;
        }
        return -1;
    }
};
