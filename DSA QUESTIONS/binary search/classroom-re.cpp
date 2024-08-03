#include <bits/stdc++.h>

using namespace std;

using lli = long long;
int n, k;
int arr[100100];
int check(int mid)
{
    lli var = 1; // maximum number of students that can be seated if the minimum separation is mid
    int l = 0, r = 1;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] - arr[l] >= mid)
        {
            var++;
            l = i;
        }
    }
    if (var >= k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int lo = 1, hi = arr[n - 1] - arr[0], ans = 1; // doesn't matter in this case.
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid) == 1)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
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