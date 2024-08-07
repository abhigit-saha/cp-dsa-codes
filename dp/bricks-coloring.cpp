#include <bits/stdc++.h>
using namespace std;
using lli = long long;
#define endl "\n"
int mod = 1000000007;
int n, m, k;
lli dp[2001][2001];

lli rec(int level, int diffCount)
{
    if (level == n)
    {
        return (diffCount == k);
    }
    if (diffCount > k)
    {
        return 0;
    }
    if (dp[level][diffCount] != -1)
    {
        return dp[level][diffCount] % mod;
    }
    lli ans = 0;
    if (level == 0)
    {
        ans = (ans + (m * rec(level + 1, diffCount)) % mod) % mod;
    }
    else
    {
        // Different color
        ans = (ans + ((m - 1) * rec(level + 1, diffCount + 1)) % mod) % mod;
        // Same color
        ans = (ans + rec(level + 1, diffCount) % mod) % mod;
    }
    return dp[level][diffCount] = ans % mod;
}

void solve()
{
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
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