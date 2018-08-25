#include <iostream>
#include <algorithm>

using namespace std;

void select_sort(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        // 找出最小值
        int pos = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[pos]) {
                pos = j;
            }
        }
        swap(a[i], a[pos]);
    }
}

int main() {
    int a[] = {5, 1, 11, 0, -1, 90, 50};
    select_sort(a, sizeof(a) / sizeof(int));
    for (auto x : a) 
        cout << x << " ";
    return 0;
}