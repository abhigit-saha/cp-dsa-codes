#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
        {
            f++;
        }
    }
    if (f % 2 == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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