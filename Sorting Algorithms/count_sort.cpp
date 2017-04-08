#include <iostream>
#include <algorithm>

using namespace std;

// 不支持负数

void count_sort(int a[], int n, int MAX) {
    // 计数
    int *count = new int[MAX + 1];
    for (int i = 0; i <= MAX; ++i)
        count[i] = 0;
    for (int i = 0; i < n; ++i)
        ++count[a[i]];
    
    // 累计小于等于i的数量 
    for (int i = 1; i <= MAX; ++i)
        count[i] += count[i - 1];
    
    int *sort = new int[n];
    for (int i = 0; i < n; ++i) {
        // 可能有重复的数字，所以要——
        --count[a[i]];
        sort[count[a[i]]] = a[i];
    }

    for (int i = 0; i < n; ++i)
        a[i] = sort[i];
    
    delete[] count;
    delete[] sort;
}

int main() {
    int a[] = {5, 1, 11, 0, 1, 90, 50};
    count_sort(a, sizeof(a) / sizeof(int) - 1, 90);
    for (auto x : a) 
        cout << x << " ";
    return 0;
}