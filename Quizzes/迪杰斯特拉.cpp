#include <iostream>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

void dijkstra(int start, vector<int> &dist, vector<int> &prev, const vector<vector<int>> &graph)
{
    // 初始化几个数组
    // visited 默认值为 false
    vector<bool> visited(dist.size(), false);
    visited[start] = true;
    for (int i = 0; i < dist.size(); ++i) {
        dist[i] = graph[start][i];
        if (dist[i] != INT_MAX) prev[i] = start;
    }
    dist[start] = 0;

    for (int i = 1; i < dist.size(); ++i) {
        // 找出当前最近的节点
        int minn = INT_MAX;
        int temp = start;
        for (int j = 0; j < dist.size(); ++j) {
            if (!visited[j] && dist[j] < minn) {
                minn = dist[j];
                temp = j;
            }
        }
        visited[temp] = true;

        // 更新 dist
        for(int j = 0; j < dist.size(); ++j) {
            if ((!visited[j]) && graph[temp][j] < INT_MAX) {
                int newdist = dist[temp] + graph[temp][j];
                if (newdist < dist[j]) {
                    dist[j] = newdist;
                    prev[j] = temp;
                }
            }
        }
    }
}

void output(int start, int end, vector<int> &prev)
{
    stack<int> s;
    while(prev[end] != start) {
        if (end == -1) {
            cout << "找不到路径！" << endl;
            return;
        }
        s.push(prev[end]);
        end = prev[end];
    }
    while (!s.empty()) {
        cout << s.top() << "->";
    }
    cout << start << endl;
}

int main()
{
    // dist 默认值为 INT_MAX
    // prev 默认值为 -1
    return 0;
}