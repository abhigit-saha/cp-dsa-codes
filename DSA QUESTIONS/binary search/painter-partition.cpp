#include <bits/stdc++.h>

using namespace std;

using lli = long long;
int n, k;
int arr[100100];
lli sum = 0;
lli check(lli mid)
{
    lli cnt = 1;
    lli curr = mid;
    for (lli i = 0; i < n; i++)
    {
        if (curr - arr[i] >= 0)
        {
            curr -= arr[i];
        }
        else
        {
            cnt++;
            curr = mid;
            if (curr - arr[i] >= 0)
            {
                curr -= arr[i];
            }
            else
            {
                return 0;
            }
        }
    }

    if (cnt <= k)
        return 1;
    else
        return 0;
}
void solve()
{
    cin >> n >> k;
    int minEl = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        minEl = min(minEl, arr[i]);
        sum += arr[i];
    }
    int lo = 0, hi = sum, ans = -1; // ans doesn't matter in this case: there would be at least 1 maximum sum (total sum for eg.)
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
    sum = 0;
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