#include <bits/stdc++.h>

using namespace std;

using lli = long long;
int arr[100100];
int diff[100100];
int n, k;
int check(int mid)
{
    if ((diff + n - lower_bound(diff, diff + n, mid)))
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
            diff[i - 1] = arr[i] - arr[i - 1];
    }
    sort(diff, diff + n);
    int lo = diff[0], hi = diff[n - 1], ans = -1; // ans can be anything in this case.
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}