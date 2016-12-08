// C(m, n) 很难写正确
class Solution {
public:
    int uniquePaths(int m, int n) {
        return combination(m + n - 2, min(m - 1, n - 1));
    }
    //C(m,n) = m!/[n!*(m-n)!]
    int combination(int m, int n) {
        long long temp = 1;
        for (int i = 0; i < n; ++i) {
            temp = temp * (m - i) / (i + 1);
        }
        return temp;
    }
};
