#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
int n, t;
int arr[100100];
int dp[105][100100];
int rec(int level, int sumTillNow)
{
    if (level > n)
    {
        return 0;
    }
    if (level == n)
    {
        return 0;
    }

    int ans = 0;

    if (dp[level][sumTillNow] != -1)
    {
        return dp[level][sumTillNow];
    }
    if (rec(level + 1, sumTillNow) == 1)
    {
        ans = 1;
    }
    else if (rec(level + 1, sumTillNow + arr[level]) == 1)
    {
        ans = 1;
    }
    dp[level][sumTillNow] = ans;
    return ans;
}

void solve()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
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