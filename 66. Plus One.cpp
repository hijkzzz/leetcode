class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for(int i = digits.size() - 1; i >= 0; --i){
            digits[i] = digits[i] + c;
            c = digits[i] > 9;
            //没有产生进位
            if(c == 0) break;
            else digits[i] = 0;
        }
        if(c == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};
