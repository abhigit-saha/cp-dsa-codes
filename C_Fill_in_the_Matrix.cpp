#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int els[m];
    for (int i = 0; i < m; i++)
    {
        els[i] = (i + 1) % m;
    }
    // eg {1,2,3,4,0};
    if (n >= m - 1)
    {
        if (m - 1 == 0)
        {
            cout << 0 << endl; // if it is 0 then the answer won't be 1, its still 0.
        }
        else
        {
            cout << m << endl;
        }
    }
    else
    {
        cout << n + 1 << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i < m - 1)
            {
                arr[i][j] = (els[j] + i) % m;
                cout << arr[i][j] << " ";
            }
            else
            {
                arr[i][j] = els[j];
                cout << arr[i][j] << " ";
            }
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