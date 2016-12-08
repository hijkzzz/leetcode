class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //token
        stringstream s(str);
        vector<string> token;
        string word;
        while(s >> word) token.push_back(word);

        //check
        if(pattern.size() != token.size()) return false;

        //a.相同字母对应相同字符串
        //b.字母和字符串唯一对应
        unordered_map<char, string> map;
        unordered_set<string> hash_set;

        for(int i =0; i < pattern.size(); i++){
            if(map.find(pattern[i]) != map.end()){
                if(map.find(pattern[i])->second != token[i]) return false;
            }
            else {
                //字符串已经被映射过
                if(hash_set.find(token[i]) != hash_set.end()) return false;
                map[pattern[i]] = token[i];
                hash_set.insert(token[i]);
            }
        }
        return true;
    }
};
