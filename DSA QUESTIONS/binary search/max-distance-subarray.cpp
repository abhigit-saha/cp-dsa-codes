#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int n, k;
int check(int mid)
{
    if (mid == 0)
        return 0; // we cannot have a gap smaller than 0
    int var = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            int d = arr[i] - arr[i - 1];
            var += (d % mid == 0) ? d / mid - 1 : d / mid;
            if (var > k)
            {
                return 0;
            }
        }
    }
    return 1;
}
void solve()
{
    cin >> n >> k;
    int maxd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
            maxd = max(arr[i] - arr[i - 1], maxd);
    }
    int lo = 1, hi = maxd, ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid) == 1)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
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