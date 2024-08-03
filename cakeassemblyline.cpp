#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, d, c;
    cin >> n >> d >> c;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> low(n), hi(n);
    for (int i = 0; i < n; i++)
    {
        low[i] = (a[i] - b[i]) + c - d;
        hi[i] = (a[i] - b[i]) + d - c;
        if (i != 0 && (low[i] > hi[i - 1] || hi[i] < low[i - 1]))
        {
            cout << "NO" << endl;
            return;
        }
    }
    sort(low.begin(), low.end());
    sort(hi.begin(), hi.end());
    if (hi[0] < low[n - 1])
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}