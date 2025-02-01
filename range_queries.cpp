#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";
int arr[1001000];
int t[4004000];

void build(int index, int l, int r)
{
    if (l == r)
    {
        t[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = t[2 * index] + t[2 * index + 1];
}

void change(int index, int l, int r, int x, int pos)
{
    if (l > pos || r < pos)
        return;
    if (l == r)
    {
        t[index] = x;
        arr[pos] = x;
        return;
    }
    int mid = (l + r) / 2;
    change(2 * index, l, mid, x, pos);
    change(2 * index + 1, mid + 1, r, x, pos);
    t[index] = t[2 * index] + t[2 * index + 1];
}

int query(int index, int l, int r, int lq, int rq)
{
    if (l > rq || lq > r)
        return 0;
    if (lq <= l && rq >= r)
        return t[index];

    int mid = (l + r) / 2;

    return query(2 * index, l, mid, lq, rq) + query(2 * index + 1, mid + 1, r, lq, rq);
}

signed main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int i, x;
            cin >> i >> x;
            i--;
            change(1, 0, n - 1, x, i);
        }
        else
        {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            cout << query(1, 0, n - 1, i, j) << endl;
        }
    }

    return 0;
}