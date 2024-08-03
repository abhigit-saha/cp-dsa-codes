#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (k - n <= 0)
    {
        cout << 1 << endl;
        return;
    }
    k -= n;
    int ans = 1;
    int count = 2;
    for (int i = 1; i <= n; i++)
    {

        k -= n - i;
        ans++;
        if (k <= 0)
        {
            break;
        }
        k -= n - i;
        ans++;
        if (k <= 0)
        {
            break;
        }
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