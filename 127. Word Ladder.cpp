// 简单的广度优先搜索
// 队列每新加入一个单词，将其从单词表中删除
class Solution {
    public:
        struct Node{
            string word;
            int dist;
            Node(string w, int d) : word(w), dist(d) {}
        };

        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
            wordList.insert(endWord);
            queue<Node> q;
            q.emplace(beginWord, 1);

            while (!q.empty()) {
                Node node = q.front();
                q.pop();

                for (int i = 0; i < node.word.length(); ++i) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        string new_word = node.word;
                        new_word[i] = c;

                        if (wordList.find(new_word) != wordList.end()) {
                            if (new_word == endWord) return node.dist + 1;
                            wordList.erase(new_word);
                            q.emplace(new_word, node.dist + 1);
                        }
                    }
                }
            }
            return 0;
        }
};
