#include <iostream>
#include <algorithm>

using namespace std;

void merge(int a[], int l, int mid, int r) {
    int *temp = new int[r - l + 1];
    int p = 0;
    int i = l;
    int j = mid + 1;

    while (i <= mid && j <= r) {
        if (a[i] < a[j])
            temp[p++] = a[i++];
        else 
            temp[p++] = a[j++];
    }

    while (i <= mid)
        temp[p++] = a[i++];

    while (j <= r)
        temp[p++] = a[j++];

    for (int i = 0; i < r - l + 1; ++i)
        a[l + i] = temp[i];

    delete[] temp;
}

void merge_sort(int a[], int l, int r) {
    if (l < r) {
        int mid = l  + (r - l) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }    
}

int main() {
    int a[] = {5, 1, 11, 0, -1, 90, 50};
    merge_sort(a, 0, sizeof(a) / sizeof(int) - 1);
    for (auto x : a) 
        cout << x << " ";
    return 0;
}