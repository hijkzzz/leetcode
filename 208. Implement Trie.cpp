class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode(char c) : val(c), isEnd(false) { }

        TrieNode* getChildren (char c) {
            for (auto x : childrens) {
                if (x->val == c)
                    return x;
            }
            return NULL;
        }

        char val;
        bool isEnd;
        //这里固定大小 26 可以避免搜索
        vector<TrieNode*> childrens;
};

class Trie {
    public:
        Trie() {
            root = new TrieNode(' ');
        }

        // Inserts a word into the trie.
        void insert(string word) {
            if(word.length() == 0) return;

            TrieNode* current = root;
            TrieNode* prev = NULL;
            int i = 0;
            while (i < word.length()) {
                prev = current;
                current = current->getChildren(word[i]);
                if(current == NULL) {
                    current = new TrieNode(word[i]);
                    prev->childrens.push_back(current);
                }
                i++;
            }

            current->isEnd = true;
        }

        // Returns if the word is in the trie.
        bool search(string word) {
            if(word.length() == 0) return false;

            TrieNode* current = root;
            int i = 0;
            while ((current = current->getChildren(word[i]))
                    && i < word.length()) {
                if (i == word.length() - 1 && current->isEnd)
                    return true;
                i++;
            }
            return false;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            if(prefix.length() == 0) return false;

            TrieNode* current = root;
            int i = 0;
            while ((current = current->getChildren(prefix[i]))
                    && i < prefix.length()) {
                if (i == prefix.length() - 1)
                    return true;
                i++;
            }
            return false;
        }

    private:
        TrieNode* root;
};
