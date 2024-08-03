#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{
    int n, m;
    cin >> n >> m;

    char arr[n][m];
    int a = 0, b = 0;
    vector<pair<int, int>> vpr;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '#')
            {
                vpr.push_back({i + 1, j + 1});
            }
        }
    }
    int sz = vpr.size();
    if (sz % 2 == 0)
    {
        auto coords = vpr[sz / 2];
        cout << coords.first << " " << coords.second << endl;
        return;
    }
    else
    {
        auto coords = vpr[(sz - 1) / 2];
        cout << coords.first << " " << coords.second << endl;
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