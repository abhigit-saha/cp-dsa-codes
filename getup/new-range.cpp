#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

struct node
{
    int sum, setAll, increment;
    bool toSet;
    node() : sum(0), setAll(0), increment(0), toSet(false) {}
};

#define MAXN 1001000
int arr[MAXN];
node t[4 * MAXN];

node merge(node a, node b)
{
    node c;
    c.sum = a.sum + b.sum;
    return c;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id].sum = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void push(int id, int l, int r)
{
    if (t[id].toSet)
    {
        t[id].sum = t[id].setAll * (r - l + 1);
        if (l != r)
        {
            t[2 * id].setAll = t[id].setAll;
            t[2 * id + 1].setAll = t[id].setAll;
            t[2 * id].increment = 0;
            t[2 * id + 1].increment = 0;
            t[2 * id].toSet = true;
            t[2 * id + 1].toSet = true;
        }
        t[id].toSet = false;
    }
    if (t[id].increment != 0)
    {
        t[id].sum += t[id].increment * (r - l + 1);
        if (l != r)
        {
            if (t[2 * id].toSet)
            {
                t[2 * id].setAll += t[id].increment;
            }
            else
            {
                t[2 * id].increment += t[id].increment;
            }
            if (t[2 * id + 1].toSet)
            {
                t[2 * id + 1].setAll += t[id].increment;
            }
            else
            {
                t[2 * id + 1].increment += t[id].increment;
            }
        }
        t[id].increment = 0;
    }
}

void update1(int id, int l, int r, int lq, int rq, int x)
{
    push(id, l, r);
    if (lq > r || rq < l)
        return;
    if (lq <= l && rq >= r)
    {
        t[id].increment = x;
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update1(2 * id, l, mid, lq, rq, x);
    update1(2 * id + 1, mid + 1, r, lq, rq, x);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update2(int id, int l, int r, int lq, int rq, int x)
{
    push(id, l, r);
    if (lq > r || rq < l)
        return;
    if (lq <= l && rq >= r)
    {
        t[id].setAll = x;
        t[id].toSet = true;
        t[id].increment = 0;
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update2(2 * id, l, mid, lq, rq, x);
    update2(2 * id + 1, mid + 1, r, lq, rq, x);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int id, int l, int r, int lq, int rq)
{
    push(id, l, r);
    if (lq > r || rq < l)
        return node();
    if (lq <= l && rq >= r)
    {
        return t[id];
    }
    int mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}

void solve()
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
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, x;
            cin >> a >> b >> x;
            a--;
            b--;
            update1(1, 0, n - 1, a, b, x);
        }
        else if (type == 2)
        {
            int a, b, x;
            cin >> a >> b >> x;
            a--;
            b--;
            update2(1, 0, n - 1, a, b, x);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            node c = query(1, 0, n - 1, a, b);
            cout << c.sum << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
