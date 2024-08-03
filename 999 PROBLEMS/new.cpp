#include <bits/stdc++.h>

using namespace std;

using lli = long long;
lli mod = 1000000007;
void solve()
{
    lli n;
    cin >> n;
    map<lli, lli> mp;
    lli ans = 0;
    for (int i = 0; i < n; i++)
    {
        lli el;
        cin >> el;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->first > el)
            {
                ans = ((ans % mod) + (it->second % mod)) % mod;
            }
        }
        mp[el]++;
    }
    cout << ans << "\n";
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