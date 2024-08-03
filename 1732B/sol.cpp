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
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            if (f == 0 && s[i] == '0')
            {
                f = 1;
                ans++;
            }
            else if (f == 1)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
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