/*
Merge sort for sorting in O(N log N) comparisons
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void merge_sort(vector<T> &a, int l, int r)
{ // sorts a from l to r index inclusive
    if (l == r)
        return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    vector<T> temp;
    int i = l, j = mid + 1;
    while (i <= mid || j <= r)
    {
        if (j == r + 1 || (i <= mid && a[i] <= a[j]))
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }
    for (int i = l; i <= r; i++)
    {
        a[i] = temp[i - l];
    }
}
int main()
{
    // example
    vector<int> a = {4, 3, 8, 1, 0, 3, 6, 8, 7, 2};
    merge_sort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}