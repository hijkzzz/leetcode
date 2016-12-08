class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (!isPrime[i]) continue;
            for (int k = i + i; k < n; k += i) isPrime[k] = false;
            count++;
        }
        return count;
    }
};
