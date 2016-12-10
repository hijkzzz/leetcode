#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void shell_sort(vector<int> &a)
{
    for (int increment = a.size() / 2; increment > 0; increment /= 2) {
        // 插入排序
        for (int i = increment; i < a.size(); ++i)  {
            int temp = a[i];
            int j = i;
            for (; j >= increment && a[j - increment] > temp; j-= increment) {
                a[j] = a[j - increment];
            }
            a[j] = temp;
        }
    }

}

int main()
{
    vector<int> a =  { 7, 6, 3, 4, 5 };
    shell_sort(a);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout," "));
    return 0;
}
