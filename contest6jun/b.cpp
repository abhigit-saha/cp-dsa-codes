#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    lli x, y;
    cin >> x >> y;
    lli c = x ^ y;
    lli pow2 = 0;
    while (c % 2 == 0)
    {
        c = c >> 1;
        pow2++;
    }

    lli ans = pow(2, pow2);
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