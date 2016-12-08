class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string kid = countAndSay(n-1);
        string ret = "";
        int l = 0, r = 0;
        while(l < kid.size()){
            //计数
            while(kid[l] == kid[r]) r++;
            //生成字符串
            ret += to_string(r - l) + to_string(kid[l] - '0');
            //下一个数
            l = r;
        }
        return ret;
    }
};
