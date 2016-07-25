class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> memory;
        return helper(input, memory);
    }
    
    vector<int> helper(string input, unordered_map<string, vector<int>> &memory) {
        if (memory.find(input) != memory.end())
            return memory[input];
        
        vector<int> result;
        int size = input.size();
        // 从运算符处分成两部分
        for (int i = 0; i < input.size(); ++i)
            if (ispunct(input[i]))
                for (int a : helper(input.substr(0, i)), memory) 
                    for (int b : helper(input.substr(i + 1)), memory) { 
                        switch (input[i]) {
                            case '+': result.push_back(a + b);
                            break;
                            case '-': result.push_back(a - b);
                            break;
                            case '*': result.push_back(a * b);
                            break;
                        }
                    }
        // 没有运算符直接返回数字         
        memory[input] = result.size() ? result : vector<int>{ stol(input) };
        return memory[input];
    }
};