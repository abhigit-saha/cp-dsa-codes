#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1" << endl;
        cout << "1 2" << endl;
        return;
    }
    if (n == 2)
    {
        cout << "1" << endl;
        cout << "1 6" << endl;
        return;
    }
    cout << n - 1 << endl;
    cout << "1 6" << endl;
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            cout << int(1.5 * i - 0.5) << " " << 3 * i << endl;
        }
        else
        {
            cout << int(1.5 * i) << " " << 3 * i << endl;
        }
    }
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