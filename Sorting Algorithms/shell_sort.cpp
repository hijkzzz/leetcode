#include <iostream>
#include <algorithm>

using namespace std;

void shell_sort(int a[], int n) {
    int gap = n;
    while (gap > 1) {
        gap = gap / 3 + 1;
        for (int i = gap; i < n; i += gap) {
            int current = a[i];
            int j = i;
            while (j - gap >= 0 && a[j - gap] > current) {
                a[j] = a[j - gap];
                j = j - gap;
            }
            a[j] = current;
        }
    }
}

int main() {
    int a[] = {5, 1, 11, 0, -1, 90, 50};
    shell_sort(a, sizeof(a) / sizeof(int));
    for (auto x : a) 
        cout << x << " ";
    return 0;
}