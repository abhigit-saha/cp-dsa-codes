#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, m;
int dp[100100];

int rec(int level)
{
    if (level == n)
        return 0;

    if (dp[level] != -1)
        return dp[level];

    int ans = 1e9;

    if (level + 1 <= n)
        ans = min(ans, rec(level + 1) + 1);

    if (level + m <= n)
        ans = min(ans, rec(level + m) + 1);

    dp[level] = ans;
    return ans;
}

void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << rec(0) << endl; // note that we are not starting from the 1st stair but the 0th stair.
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