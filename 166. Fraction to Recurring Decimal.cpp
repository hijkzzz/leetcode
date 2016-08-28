class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        if (numerator < 0 ^ denominator < 0) result += "-";

        // 防止溢出，转换成 int64_t
        int64_t a = abs((int64_t) numerator);
        int64_t b = abs((int64_t) denominator);

        result += to_string(a / b);
        if (a % b == 0) return result;

        // 计算小数部分，记录余数来确定重复
        result += ".";
        unordered_map<int64_t, int> dup; // [余数, 由该余数计算出的小数的位置]
        for (int64_t r = a % b; r != 0; r = r * 10 % b) {
            int64_t digit = r * 10 / b;
            // 余数重复
            if (dup.find(r) != dup.end()) {
                result.insert(dup[r], "(");
                result += ")";
                break;
            } else {
                result += to_string(digit);
                dup[r] = result.size() - 1;
            }
        }

        return result;
    }
};
