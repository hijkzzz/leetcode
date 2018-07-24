/*
 * 原地算法
 * 从后往前替换
 */
class Solution {
    public:
        void replaceSpace(char *string, int length) {
            int blanknumber = 0;
            int i;
            for (i = 0; string[i] != '\0'; i++) {
                if (string[i] == ' ') {
                    blanknumber++;
                }
            }
            int k = i + 2 * blanknumber;
            if (k > length)
                return;
            string[k]='\0';//此行必不可少
            int point1 = i - 1, point2 = k-1;
            for (; point1 >= 0 && point2 > point1; point1--) {
                if (string[point1] == ' ') {
                    string[point2--] = '0';
                    string[point2--] = '2';
                    string[point2--] = '%';
                } else
                    string[point2--] = string[point1];
            }
        }
};
