#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int j = 0;
    int ans = 0;
    // traversing the second string first and if theres a match
    // then incrementing the pointer at the first string
    for (int i = 0; i < m && j < n; i++)
    {
        if (b[i] == a[j])
        {
            j++;
            ans++;
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