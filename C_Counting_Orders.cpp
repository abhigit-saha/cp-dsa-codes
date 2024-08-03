#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

lli mod = 1000000007;
void solve()
{
    int n;
    cin >> n;

    vector<lli> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    lli ans = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int elAvailable;

        elAvailable = a.end() - upper_bound(a.begin(), a.end(), b[i]) - (n - 1 - i);
        if (elAvailable <= 0)
        {
            cout << 0 << endl;
            return;
        }

        ans = ((ans % mod) * (elAvailable % mod)) % mod;
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