#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void quick_sort(int l, int r, vector<int> &a)
{
    if(r <= l) return;

    int p = l;
    for(int i = l + 1; i <= r; i++){
        //if j<=p a[j] < a[l]
        if(a[i] < a[l])
            swap(a[++p], a[i]);
    }
    swap(a[p], a[l]);
    quick_sort(l, p - 1, a);
    quick_sort(p + 1, r, a);
}

int main()
{
    vector<int> test{1, 32, 4, 5, 21, 3, 8};
    quick_sort(0, test.size() - 1, test);
    copy(test.begin(), test.end(), ostream_iterator<int>(cout," "));
    return 0;
}
