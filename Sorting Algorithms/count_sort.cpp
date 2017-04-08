#include <iostream>
#include <algorithm>

using namespace std;

void count_sort(int a[], int n) {

}

int main() {
    int a[] = {5, 1, 11, 0, -1, 90, 50};
    count_sort(a, sizeof(a) / sizeof(int) - 1);
    for (auto x : a) 
        cout << x << " ";
    return 0;
}