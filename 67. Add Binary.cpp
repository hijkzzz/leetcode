class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0 || carry != 0){
            int digitA = i < 0 ? 0 : a[i--] - '0';
            int digitB = j < 0 ? 0 : b[j--] - '0';

            int current = digitA ^ digitB ^ carry;
            carry = (digitA & digitB) || (digitA & carry) || (digitB & carry);
            result = static_cast<char>(current + '0') + result;
        }
        return result;
    }
};
