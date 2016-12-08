class Solution {
    public:
        string simplifyPath(string path) {
            string token;
            stringstream ss(path);
            vector<string> tokens;

            while(getline(ss, token, '/')){
                if(token=="." || token == "") continue;
                else if(token == ".."){
                    if(tokens.size() != 0)  tokens.pop_back();
                }
                else tokens.push_back(token);
            }

            if(tokens.size() == 0) return "/";
            string result = "";
            for(int i = 0; i < tokens.size(); ++i)
                result += '/' + tokens[i];
            return result;
        }
};
