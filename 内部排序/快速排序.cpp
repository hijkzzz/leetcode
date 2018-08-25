#include <iostream>
#include <algorithm>

using namespace std;

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        // 比 a[l] 小的交换到左侧
        // p 指向置换位
        int p = l;
        for (int i = l + 1; i <= r; ++i) {
            if (a[i] < a[l])
                swap(a[i], a[++p]);
        }
        swap(a[l], a[p]);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }
}

int main() {
    int a[] = {5, 1, 11, 0, -1, 90, 50};
    quick_sort(a, 0, sizeof(a) / sizeof(int) - 1);
    for (auto x : a) 
        cout << x << " ";
    return 0;
}