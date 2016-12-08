class Solution {
public:
    bool isHappy(int n) {
        set<int> cycle;

        while(n != 1){
            // 如果出现循环则返回 false
            if(cycle.find(n) != cycle.end()) return false;
            else cycle.insert(n);

            int next = 0;
            while(n){
                next += (n % 10) * (n % 10);
                n /= 10;
            }
            n = next;
        }
        return true;
    }
};
