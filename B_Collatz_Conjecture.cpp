#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    while (k--)
    {

        x++;
        if (x % y == 0)
        {
            while (x % y == 0)
            {
                x /= y;
            }
        }
    }
    cout << x << endl;
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