#include <bits/stdc++.h>

using namespace std;
#define endl "\n";

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int minMax = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i != 0)
        {
            int maxTwo = max(arr[i], arr[i - 1]);
            minMax = min(maxTwo, minMax);
        }
    }
    cout << minMax - 1 << endl;
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