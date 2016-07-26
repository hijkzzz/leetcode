class Solution {
    public:
        bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
            vector<unordered_set<int>> graph = convert_to_graph(numCourses, prerequisites);
            vector<int> indegree = compute_indegree(graph);

            for (int i = 0; i < numCourses; ++i) {
                int j = 0;
                for (; j < numCourses; ++j) {
                    if(indegree[j] == 0) break;
                }
                //没有找到 入度 == 0 的节点
                if(j == numCourses) return false;
                //删除节点
                indegree[j] = -1;
                for (auto after : graph[j]) {
                    --indegree[after];
                }
            }

            return true;
        }

        vector<unordered_set<int>> convert_to_graph(int numCourses, vector<pair<int, int>>& prerequisites)
        {
            vector<unordered_set<int>> graph(numCourses);
            for (auto & p : prerequisites) {
                //先修课 -->> 后修课
                graph[p.second].insert(p.first);
            }
            return graph;
        }

        vector<int> compute_indegree(vector<unordered_set<int>> graph)
        {
            vector<int> indegree(graph.size());
            for (int i = 0; i < graph.size(); ++i) {
                for (auto after : graph[i]) {
                    ++indegree[after];
                }
            }
            return indegree;
        }
};
