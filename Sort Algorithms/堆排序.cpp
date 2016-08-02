#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#define left_child(i) (2 * (i) + 1)

// 下溯
void perc_down(vector<int> &a, int i, int N)
{
    int temp = a[i];
    // 还有子节点
    while (left_child(i) < N) {
        int child = left_child(i);
        // 找到较大的儿子节点
        if (child != N - 1 && a[child + 1] > a[child])
            ++child;

        if (a[child] > temp)
            a[i] = a[child];
        else
            break;
        i = child;
    }
    a[i] = temp;
}

// 堆排序
void heap_sort(vector<int> &a)
{
    int N = a.size();
    // 建立堆
    for (int i = N / 2; i >= 0; --i)
        perc_down(a, i, N);
    for (int i = N - 1; i > 0; --i) {
        // 最大元素放到后面
        swap(a[0], a[i]);
        perc_down(a, 0, i);
    }
}

int main()
{
    vector<int> a =  { 7, 6, 3, 4, 5 };
    heap_sort(a);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout," "));
    return 0;
}
