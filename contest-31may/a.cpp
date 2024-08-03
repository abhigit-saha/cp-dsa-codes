#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

using lli = long long;

void solve()
{
    lli a, b;
    cin >> a >> b;
    int count = 0;
    while (b != 0)
    {
        b = (b >> 1);
        count++;
    }
    cout << count - 1 << endl;
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