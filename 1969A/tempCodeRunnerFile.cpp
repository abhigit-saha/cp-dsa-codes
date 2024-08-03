#include <bits/stdc++.h>

using namespace std;
#define endl "\n";
using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 3;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[a[i]])
        {
            ans = 2;
            break;
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