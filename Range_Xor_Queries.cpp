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
    t[index] = t[2 * index] ^ t[2 * index + 1];
}
void change(int index, int l, int r, int pos, int x)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        t[index] = x;
        arr[pos] = x;
        return;
    }
    int mid = (l + r) / 2;
    change(2 * index, l, mid, pos, x);
    change(2 * index + 1, mid + 1, r, pos, x);
    t[index] = min(t[2 * index], t[2 * index + 1]);
}
int query(int index, int l, int r, int ql, int qr)
{
    if (ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return query(2 * index, l, mid, ql, qr) ^ query(2 * index + 1, mid + 1, r, ql, qr);
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
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(1, 0, n - 1, a, b) << endl;
    }

    return 0;
}