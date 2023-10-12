/*
Segment Tree data structure for fast point updates and range queries.
Performs point updates and range queries in log N per query.
*/

#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct segTree
{
    int n;
    vector<T> t;
    T initial;
    segTree(int _n, T _initial)
    {
        n = _n;
        t.resize(2 * n);
        initial = _initial;
        for (auto &i : t)
            i = initial;
    }
    void update(int position, T value)
    {
        position += n;
        t[position] = value;
        while (position > 1)
        {
            position >>= 1;
            t[position] = merge(t[position << 1], t[(position << 1) | 1]);
        }
    }
    T query(int left, int right)
    {
        left += n;
        right += n;
        T res = initial;
        while (left < right)
        {
            if (left & 1)
            {
                res = merge(res, t[left]);
                left++;
            }
            if (!(right & 1))
            {
                res = merge(res, t[right]);
                right--;
            }
            left >>= 1;
            right >>= 1;
        }
        if (left == right)
            res = merge(res, t[left]);
        return res;
    }
    T merge(T a, T b)
    {
        T res;
        res = a + b;
        return res;
    }
};

int main()
{
    int n; // Number of elements
    cin >> n;
    vector<int> a(n + 1);
    segTree<int> tree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tree.update(i, a[i]);
    }
    int q; // Number of queries
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int type = 0;
        cin >> type;
        if (type == 1) // Update query
        {
            int position, value;
            cin >> position >> value;
            a[position] = value;
            tree.update(position, value);
        }
        else // range sum query
        {
            int left, right;
            cin >> left >> right;
            cout << tree.query(left, right) << endl;
        }
    }
}