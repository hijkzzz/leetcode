#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void insertion_sort(vector<int> &a)
{
    for (int i = 1; i < a.size(); ++i) {
        int temp = a[i];
        int j = i;
        for (; j > 0 && a[j - 1] > temp; --j) {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}

int main()
{
    vector<int> a =  { 7, 6, 3, 4, 5 };
    insertion_sort(a);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout," "));
    return 0;
}
