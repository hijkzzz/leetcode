class Solution {
public:
    static bool cmp(int left, int right) {
        string a = to_string(left);
        string b = to_string(right);
        
        return stol(a + b) < stol(b + a);
    }
    
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        
        string res = "";
        for (int x : numbers) {
            res += to_string(x);
        }
        return res;
    }
};
