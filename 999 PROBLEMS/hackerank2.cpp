#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    lli n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    lli remprof = 1;
    lli rem = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'c')
        {
            remprof = ((remprof % m) * (42 % m)) % m;
            rem = ((rem % m) * (42 % m)) % m;
        }
        else if (s[i] == 'v')
        {
            remprof = ((remprof % m) * (10 % m)) % m;
            rem = ((rem % m) * (10 % m)) % m;
        }
        else
        {
            remprof = ((remprof % m) * (5 % m)) % m;
            rem = ((rem % m) * (10 % m)) % m;
        }
    }

    if (remprof == rem)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
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