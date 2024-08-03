#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    lli x, y, z, k;
    cin >> x >> y >> z >> k;
    lli ans = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (k % (i * j) != 0)
            {
                continue;
            }
            else
            {
                ans = max(ans, 1LL * (x - i + 1) * (y - j + 1) * (z - k / (i * j) + 1));
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