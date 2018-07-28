/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode*> ret;
        if(graph.empty())
            return ret;
        
        map<DirectedGraphNode*,int> in; //in为入度
        stack<DirectedGraphNode*>   s;  //保存入度为零的节点
        for(auto e:graph){
            for(auto i:e->neighbors)
                ++in[i];              //记录每个节点的入度
        }
        
        for(auto e:graph)
           if(0==in[e])
               s.push(e);         //入度为零的节点入栈
        
        while(!s.empty()){        //BFS遍历,搜寻入度为零的节点
            DirectedGraphNode* cur=s.top();
            s.pop();             //当前节点出栈时，它的相邻节点入度都减一
            ret.push_back(cur);   
            for(auto e:cur->neighbors){
                if(--in[e]==0)    //减一后为零则入栈
                    s.push(e);
            }
        }       
        return ret;
    }
};
