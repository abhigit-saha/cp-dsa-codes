#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    int ans = n / 4;
    if (n < 4)
    {
        ans = n / 2;
        cout << ans << endl;
        return;
    }
    if (n % 4 == 2)
    {
        ans++;
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