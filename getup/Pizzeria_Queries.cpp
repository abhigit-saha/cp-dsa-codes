#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int arr[1001000];
struct node
{
    int beforemin, aftermin;
    node()
    {
        beforemin = 1e9;
        aftermin = 1e9;
    }
};
node merge(node a, node b)
{
    node c;
    c.beforemin = min(a.beforemin, b.beforemin);
    c.aftermin = min(a.aftermin, b.aftermin);
    return c;
}
node t[4004000];

void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id].beforemin = arr[l] - l;
        t[id].aftermin = arr[l] + l;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int k, int x)
{
    if (l > k || r < k)
        return;
    if (l == r)
    {
        t[id].beforemin = x - l;
        t[id].aftermin = x + l;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, k, x);
    update(2 * id + 1, mid + 1, r, k, x);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int id, int l, int r, int lq, int rq)
{
    if (l > rq || r < lq)
        return node();
    if (lq <= l && rq >= r)
    {
        return t[id];
    }
    int mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
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
            int k, x;
            cin >> k >> x;
            k--;
            update(1, 0, n - 1, k, x);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            node a = query(1, 0, n - 1, 0, k);         // before
            node b = query(1, 0, n - 1, k + 1, n - 1); // after
            int beforeans = a.beforemin + k, afterans = b.aftermin - k;
            cout << min(beforeans, afterans) << endl;
        }
    }
}