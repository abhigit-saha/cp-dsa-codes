#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, k;
    cin >> n, k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0, r = arr.size() - 1;
    int ans = 0;
    bool solvable = true;
    while (l < r)
    {
        if (arr[l] + k < arr[r])
        {
            solvable = false;
            break;
        }
        ans++;
        l++;
        r--;
    }
    if (!solvable)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
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