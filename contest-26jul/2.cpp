#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    char m[n][n];

    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
        {
            m[i][j] = row[j];
        }
    }

    for (int i = 0; i < n; i += k)
    {
        for (int j = 0; j < n; j += k)
        {
            cout << m[i][j];
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