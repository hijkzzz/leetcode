class Solution {
    public:
        int  NumberOf1(int n) {
            unsigned int temp = n;
            temp = (temp & 0x55555555) + ((temp >> 1) & 0x55555555);
            temp = (temp & 0x33333333) + ((temp >> 2) & 0x33333333);
            temp = (temp & 0x0f0f0f0f) + ((temp >> 4) & 0x0f0f0f0f);
            temp = (temp & 0x00ff00ff) + ((temp >> 8) & 0x00ff00ff);
            temp = (temp & 0x0000ffff) + ((temp >> 16) & 0x0000ffff);
            return temp;
        }
};
