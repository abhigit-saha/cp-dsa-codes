#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    lli n;
    cin >> n;
    lli l = 1, r = n + 1;
    lli dcr = 1;
    while (l < r)
    {
        if (l != 1 && (n - l * (l + 1) / 2) % l == 0)
        {
            cout << l << endl;
            return;
        }
        l++;
        if (r == n || r == n + 1)
        {
            r -= 1;
        }
        else
        {
            dcr++;
            r -= dcr;
        }
    }
    if (n - r * (r + 1) / 2 < 0)
    {
        cout << -1 << endl;
        return;
    }
    if ((n - r * (r + 1) / 2) % r == 0)
    {
        cout << r << endl;
        return;
    }
    else
    {
        cout << -1 << endl;
        return;
    }
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