#include <bits/stdc++.h>

using namespace std;

using lli = long long;
lli n, s;
int check(lli mid)
{
    lli originalMid = mid;
    int digitSum = 0;
    while (mid > 0)
    {
        digitSum += mid % 10;
        mid /= 10;
    }
    return originalMid - digitSum >= s;
}
void solve()
{
    cin >> n >> s;
    lli lo = 1, hi = n, ans = n + 1;
    while (lo <= hi)
    {
        lli mid = lo + (hi - lo) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << n - ans + 1 << endl;
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