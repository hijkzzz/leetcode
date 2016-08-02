#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void merge(vector<int> &a, int l, int m, int r)
{
    vector<int> temp(a.size(), 0);
    int pos = 0;

    int i = l, j = m;
    while (i < m && j <= r)
        if (a[i] < a[j])
            temp[pos++] = a[i++];
        else
            temp[pos++] = a[j++];

    while (i < m)
        temp[pos++] = a[i++];
    while (j <= r)
        temp[pos++] = a[j++];

    for (int k = 0; k < pos; ++k)
        a[l + k] = temp[k];
}

void merge_sort(vector<int> &a, int l, int r)
{
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid + 1, r);
    }
}

int main()
{
    vector<int> a =  { 7, 6, 3, 4, 5 };
    merge_sort(a, 0, a.size() - 1);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout," "));
    return 0;
}
