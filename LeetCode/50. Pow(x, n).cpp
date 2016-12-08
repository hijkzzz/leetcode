class Solution {
    public:
        double myPow(double x, int n) {
            if(n > 0)
                return power(x, n);
            else
                return (double)1/power(x, -1 * (long long)n);
        }

        double power(double x, long long n){
            if(n == 0) return 1;
            double temp = power(x*x, n >> 1);
            //如果是奇数
            if(n&1) temp *= x;
            return temp;
        }
};
