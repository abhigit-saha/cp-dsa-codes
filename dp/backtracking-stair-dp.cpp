#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
int dp[100100];
int n;
int rec(int level)
{
    // pruning
    if (level > n)
    {
        return 0; // null case of counting problem.
    }
    // base case
    if (level == n)
    {
        return 1; // base case of counting problem
    }
    // general structure: for(all choices){ if(choice is valid) move to the choice}
    if (dp[level] != -1)
    {
        return dp[level];
    }
    int ans = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (level + i <= n)
        {
            int ways = rec(level + i);
            ans += ways;
        }
    }
    dp[level] = ans;
    return ans;
} // returns number of ways to reach to the top from this level
void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(1) << endl;
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