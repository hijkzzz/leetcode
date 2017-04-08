#include <iostream>
#include <algorithm>

using namespace std;

void insert_sort(int a[], int n) {
    // i 控制要插入的元素
    for (int i = 1; i < n; ++i) {
        int current = a[i];
        int j = i;
        while (j - 1 >= 0 && a[j - 1] > current) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = current;
    }
}

int main() {
    int a[] = {5, 1, 11, 0, -1, 90, 50};
    insert_sort(a, sizeof(a) / sizeof(int));
    for (auto x : a) 
        cout << x << " ";
    return 0;
}