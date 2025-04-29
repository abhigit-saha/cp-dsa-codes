#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(o) (o).begin(), (o).end()
int arr[1001000];
vector<int> t[4004000];
void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id].push_back(arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id].resize(t[2 * id].size() + t[2 * id + 1].size());
    merge(all(t[2 * id]), all(t[2 * id + 1]), t[id].begin());
}

int query(int id, int l, int r, int lq, int rq, int k)
{
    if (l > rq || r < lq)
        return 0;
    if (lq <= l && rq >= r)
    {
        int ans = upper_bound(all(t[id]), k) - t[id].begin();
        return ans;
    }
    int mid = (l + r) / 2;
    return query(2 * id, l, mid, lq, rq, k) + query(2 * id + 1, mid + 1, r, lq, rq, k);
}
signed main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> lastSeen;

    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        if (lastSeen[arr[i]] == 0)
        {
            arr[i] = 0;
        }
        else
        {

            arr[i] = lastSeen[arr[i]];
        }
        lastSeen[val] = i + 1;
    }
    for (int i = 0; i < n; i++)
        arr[i]--;

    build(1, 0, n - 1);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(1, 0, n - 1, a, b, a - 1) << endl;
    }
}
