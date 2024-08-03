#include <bits/stdc++.h>

using namespace std;
#define endl "\n";
using lli = long long;
lli gcd(lli a, lli b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}
void solve()
{
    lli m, n;
    cin >> n >> m;
    vector<lli> a(n), b(m);

    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lli i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    lli g = 0;
    for (int i = 1; i < n; i++)
    {
        g = gcd(g, a[i] - a[0]);
    }
    for (lli j = 0; j < m; j++)
    {
        lli gj = gcd(a[0] + b[j], g);
        cout << gj << " ";
    }
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}