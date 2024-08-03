#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

using lli = long long;

void solve()
{
    lli n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
    {
        cout << "0" << endl;
        return;
    }
    if (n == 0 && m == 1)
    {
        cout << "1" << endl;
        return;
    }
    if (n == 0 && m > 1)
    {
        cout << "3" << endl;
        return;
    }
    lli ans = 0;

    for (lli i = ((n - m) > 0 ? n - m : 0); i <= (n + m); i++)
    {
        ans |= i;
    }
    cout << ans << endl;
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