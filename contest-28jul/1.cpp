#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    int ans = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        int el;
        cin >> el;
        if (i % 2 == 1)
        {
            ans = max(ans, el);
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