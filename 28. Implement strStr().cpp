class Solution {
    public:
        vector<int> getNext(string needle){
            vector<int> next(needle.size(), 0);
            int k = 0;

            for(int i = 1; i < next.size(); i++){
                while(needle[i] != needle[k] && k != 0)
                    k = next[k - 1];
                if(needle[i] == needle[k])
                    k++;
                next[i] = k;

            }
            return next;
        }

        int strStr(string haystack, string needle) {
            if(needle == "") return 0;
            vector<int> next = getNext(needle);

            //父串和子串的下标
            for(int i = 0, j = 0; i < haystack.size(); i++){
                while(haystack[i] != needle[j] && j != 0)
                    j = next[j - 1];
                //如果匹配
                if(haystack[i] == needle[j])
                    j++;
                if(j == needle.size())
                    return i - j + 1;
            }
            return -1;
        }
};
