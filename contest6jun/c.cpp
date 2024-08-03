#include <bits/stdc++.h>

using namespace std;

using lli = long long;

lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    double hsum = 0;
    lli pdt = 1;

    lli g = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        pdt *= arr[i];
        if (i != n - 1)
        {
            g = gcd(g, arr[i]);
        }
    }

    lli lcm = pdt / g;
    lli sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = lcm / arr[i];
    }
    if (sum >= lcm)
    {
        cout << -1 << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << sum << lcm << endl;
    cout << endl;
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