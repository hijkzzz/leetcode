/*
 *  new  分配内存，返回内存句柄
 *  del  删除指定内存块，参数为内存句柄
 *  def  整理内存，并对齐到高位
 *  内存句柄为从 0 开始的序号
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct mem_node {
    int start;
    int end;
    // -1 表示空闲
    int handle;

    mem_node(int s, int e, int h) : start(s), end(e), handle(h) {}
    int getSize() {
        return end - start + 1;
    }
};

void display(list<mem_node> &l) {
    for (auto &n : l) {
        cout << "handle "<<n.handle<< " "<< n.start <<" -> " << n.end << endl;
    }
}

int main()
{
    list<mem_node> l;
    int count, max_size;
    cin >> count >> max_size;
    l.push_back(mem_node(1, max_size, -1));
    int num = 1;

    while (count--) {
        string func;
        cin >> func;
        if (func == "new") {
            int n;
            cin >> n;
            int flag = 0;
            for (auto i = l.begin(); i != l.end(); ++i) {
                if (i->handle == -1 && i->getSize() >= n) {
                    if (i->getSize() > n) {
                        auto p = i;
                        l.insert(++p, mem_node(i->start + n, i->end, -1));
                    }
                    i->handle = num++;
                    i->end = i->start + n - 1;
                    flag = 1;
                    cout << i->handle << endl;
                    break;
                }
            }
            if (!flag) cout << "NULL" << endl;

        } else if (func == "del") {
            int handle;
            cin >> handle;
            int flag = 0;
            for (auto i = l.begin(); i != l.end(); ++i) {
                if (i->handle == handle) {
                    i->handle = -1;
                    auto p = i;
                    --p;
                    if (p->handle == -1) {
                        p->end = i->end;
                        l.erase(i);
                        i = p;
                    }
                    p = i;
                    ++p;
                    if (p->handle == -1) {
                        i->end = p->end;
                        l.erase(p);
                    }
                    flag = 1;
                    break;
                }
            }
            if (!flag) cout << "ILLEGAL_OPERATION" << endl;

        } else if (func == "def") {
            for (auto i = l.begin(); i != l.end(); ++i) {
                if (i->handle == -1) l.erase(i);
            }
            int end = max_size;
            for (auto i = l.rbegin(); i != l.rend(); ++i) {
                int size = i->getSize();
                i->end = end;
                i->start = end - size + 1;
                end -= size;
            }
            l.insert(l.begin(), mem_node(1, end, -1));
        }
        //display(l);
    }

    return 0;
}
