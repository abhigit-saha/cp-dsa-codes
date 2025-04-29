#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int arr[1001000];
struct node
{
    int lower;
    int upper;
    int number;
    node()
    {
        lower = 0;
        upper = 1e9;
        number = 0;
    }
};
node merge(node a, node b)
{
    node c;
    c.lower = min(a.lower, b.lower);
    c.upper = max(a.upper, b.upper);
    c.number = a.number + b.number;
    return c;
}

node t[4004000];

void build(int index, int l, int r)
{
    if (l == r)
    {
        node c;
        c.lower = arr[l];
        c.upper = arr[l];
        c.number = 1;
        t[index] = c;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}

void change(int index, int l, int r, int k, int x)
{
    if (k > r || k < l)
        return;
    if (l == r)
    {
        arr[l] = x;
        node c;
        c.lower = arr[l];
        c.upper = arr[l];
        t[index] = c;
        return;
    }
    int mid = (l + r) / 2;
    change(2 * index, l, mid, k, x);
    change(2 * index + 1, mid + 1, r, k, x);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}
node query(int index, int l, int r, int lq, int rq)
{
    node c;
    if (lq <= t[index].lower && rq >= t[index].upper)
    {
        return t[index];
    }
    int mid = (l + r) / 2;
    return merge(query(2 * index, l, mid, lq, rq), query(2 * index + 1, mid + 1, r, lq, rq));
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
        char ch;
        cin >> ch;
        if (ch == '!')
        {
            int k, x;
            cin >> k >> x;
            k--;

            change(1, 0, n - 1, k, x);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            node c = query(1, 0, n - 1, a, b);
            cout << c.number << endl;
        }
    }
}