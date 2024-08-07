#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
int n, x, k;
int t[100100], s[100100];
int dp[101][101][101];
int rec(int level, int time_taken, int attempted)
{

    if (level == n)
    {
        return 0;
    }
    if (dp[level][time_taken][attempted] != -1)
    {
        return dp[level][time_taken][attempted];
    }
    int ans = rec(level, time_taken, attempted); // don't take the current level

    if (time_taken + t[level] <= x && attempted + 1 <= k)
    {
        ans = max(ans, s[level] + rec(level + 1, time_taken + t[level], attempted + 1));
    }

    return dp[level][time_taken][attempted] = ans;
}
void solve()
{
    cin >> n >> k >> x;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
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