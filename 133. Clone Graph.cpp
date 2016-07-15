/*
 * 因为子节点可能已经生成过，所以需要建立一张查询表
 */
class Solution {
    public:
        using table = unordered_map<int, UndirectedGraphNode *>;

        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if (node == NULL) return NULL;

            table t;
            return clone(node, t);
        }

        UndirectedGraphNode *clone(UndirectedGraphNode *n, table &t) {
            UndirectedGraphNode *temp = new  UndirectedGraphNode(n->label);
            t.insert(make_pair(temp->label, temp));

            //复制子节点
            for (auto neighbor : n->neighbors) {
                auto i = t.find(neighbor->label);
                if (i != t.end()) {
                    temp->neighbors.push_back(i->second);
                } else {
                    temp->neighbors.push_back(clone(neighbor, t));
                }
            }
            return temp;
        }
};
