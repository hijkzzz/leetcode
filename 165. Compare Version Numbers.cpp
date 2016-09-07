class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while(i < version1.size() || j < version2.size()){
            int digit1 = 0;
            while(i < version1.size() && version1[i] != '.')
                digit1 += digit1 * 10 + version1[i++] - '0';
            i++;

            int digit2 = 0;
            while(j < version2.size() && version2[j] != '.')
                digit2 += digit2 * 10 + version2[j++] - '0';
            j++;

            if(digit1 != digit2)
                return digit1 < digit2 ? -1 : 1;
        }
        return 0;
    }
};
