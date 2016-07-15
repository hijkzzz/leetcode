class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
            vector<unordered_set<int>> graph(n, unordered_set<int>());
            vector<int> degree(n, 0);

            for (auto &p : edges) {
                graph[p.first].insert(p.second);
                ++degree[p.second];
                graph[p.second].insert(p.first);
                ++degree[p.first];
            }

            queue<int> q;
            for (int i = 0; i < degree.size(); i++) {
                if (degree[i] == 1) q.push(i);
            }

            //剩余的节点数
            while (n > 2) {
                n -= q.size();

                //删除外面一层
                while (!q.empty()) {
                    int k = q.front();
                    q.pop();
                    degree[k] = -1;

                    for (auto x : graph[k]) {
                        --degree[x];
                    }
                }

                for (int i = 0; i < degree.size(); i++) {
                    if (degree[i] == 1) q.push(i);
                }
            }

            vector<int> result;
            for (int i = 0; i < degree.size(); i++) {
                if (degree[i] >= 0) result.push_back(i);
            }

            return result;
        }
};
