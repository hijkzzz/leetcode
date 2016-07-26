class Solution {
    public:
        const int base = 1337;

        int f(int a, int n) {

            int res = 1;
            while (n--) {
                res = (res * a) % base;
            }
            return res;
        }

        //f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;
        int superPow(int a, vector<int>& b) {
            if (b.size() == 0) return 1;
            a %= base;

            int n = b.back();
            b.pop_back();
            return (f(superPow(a, b), 10) * f(a, n)) % base;
        }
};
