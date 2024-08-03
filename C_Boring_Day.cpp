#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    lli sum = 0;
    vector<lli> pfx;
    pfx[0] = 0;
    lli ans = 0;
    for (int i = 1; i <= n; i++)
    {
        pfx[i] = pfx[i - 1] + arr[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (pfx[j + 1] - pfx[i + 1] + arr[i] >= l && pfx[j + 1] - pfx[i + 1] + arr[i] <= r)
            {
                ans++;
                i = j;
                break;
            }
        }
    }
    cout << sum << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}