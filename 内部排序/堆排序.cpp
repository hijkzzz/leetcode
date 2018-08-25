#include <iostream>
#include <algorithm>
using namespace std;
// 最大堆实现从小到大排序

void down_heap(int a[], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // 找出最大元素，和最大的交换
    int largest = i;
    if (l <= n - 1 && a[l] > a[i]) 
        largest = l;
    if (r <= n - 1 && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        // 继续下沉
        down_heap(a, largest, n);
    }
}

void build_heap(int a[], int n) {
    // 从最后一个父节点开始下沉
    for (int i = (n - 1) / 2; i >= 0; i--) {
        down_heap(a, i, n);
    }
}

void heap_sort(int a[], int n) {
    build_heap(a, n);
    for (int i = n - 1; i > 0; i--) {
        // 取出堆顶放在数组后
        swap(a[0], a[i]);
        // 新元素下沉
        down_heap(a, 0, --n);
    }
}

int main() {
    int a[] = {5, 1, 11, 0, -1, 90, 50};
    heap_sort(a, sizeof(a) / sizeof(int));
    for (auto x : a) 
        cout << x << " ";
    return 0;
}