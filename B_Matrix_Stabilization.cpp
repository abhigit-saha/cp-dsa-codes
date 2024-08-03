#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    lli n, m;
    cin >> n >> m;
    lli mx[n + 2][m + 2];
    for (lli i = 0; i <= n + 1; i++)
    {
        for (lli j = 0; j <= m + 1; j++)
        {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
            {
                mx[i][j] = 0;
            }
            else
            {
                cin >> mx[i][j];
            }
        }
    }
    // handle single row and col cases before

    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= m; j++)
        {
            lli el1 = mx[i - 1][j], el2 = mx[i][j - 1], el3 = mx[i + 1][j], el4 = mx[i][j + 1];
            lli maxEl = max(el1, max(el2, max(el3, el4)));
            if (mx[i][j] > maxEl)
            {
                mx[i][j] = maxEl;
            }
        }
    }

    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j <= m; j++)
        {
            cout << mx[i][j] << " ";
        }
        cout << endl;
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