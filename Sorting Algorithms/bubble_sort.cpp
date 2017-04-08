#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main() {
    int a[] = {5, 1, 11, 0, -1, 90, 50};
    bubble_sort(a, sizeof(a) / sizeof(int));

    for (auto x : a) 
        cout << x << " ";
    return 0;
}