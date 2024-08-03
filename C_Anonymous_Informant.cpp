#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    lli n, k;
    cin >> n >> k;
    lli sum = 0;
    vector<lli> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    k = min(n, k);
    int s = n - 1;
    while (k--)
    {
        if (a[s] > n)
        {
            cout << "No" << endl;
            return;
        }
        s -= a[s];
        s = ((s + n) % n) % n;
    }
    cout << "Yes" << endl;
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