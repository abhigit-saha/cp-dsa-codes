#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
void change(int index, int l, int r, int pos, int x)
{
    if (l > pos || pos > r)
        return;
    if (l == r)
    {
        t[index] += x;
        arr[pos] += x;
        return;
    }

    int mid = (l + r) / 2;
    change(2 * index, l, mid, pos, x);
    change(2 * index + 1, mid + 1, r, pos, x);
    t[index] = t[2 * index] + t[2 * index + 1];
}
int query(int index, int l, int r, int lq, int rq)
{
    if (lq > r || rq < l)
        return 0;
    if (lq <= l && rq >= r)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return query(2 * index, l, mid, lq, rq) + query(2 * index + 1, mid + 1, r, lq, rq);
}
signed main()
{
    int n, q;
    cin >> n >> q;
    int els[n];
    for (int i = 0; i < n; i++)
    {
        cin >> els[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    build(1, 0, n - 1);
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;

            change(1, 0, n - 1, a, u);
            if (b + 1 < n)
            {
                change(1, 0, n - 1, b + 1, -u);
            }
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << query(1, 0, n - 1, 0, k) + els[k] << endl;
        }
    }

    return 0;
}