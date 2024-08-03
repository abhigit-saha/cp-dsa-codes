#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    lli n, x;
    cin >> n >> x;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;

        arr.emplace_back(el);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xr = arr[i];
            for (int k = i; k < j; k++)
            {
                xr ^= arr[i + 1];
            }
        }
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