class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //对应字母指向同一个数字
        vector<int> sMap(256, 0);
        vector<int> tMap(256, 0);
        int cnt = 1;

        for(int i = 0; i < s.length(); i++){
            char sc = s[i];
            char tc = t[i];
            //如果不指向同一个数字
            if(sMap[sc] != tMap[tc])
                return false;
            else if(sMap[sc] == 0)
                sMap[sc] = tMap[tc] = cnt++;
        }
        return true;
    }
};
