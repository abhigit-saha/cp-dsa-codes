#include <bits/stdc++.h>

using namespace std;

using lli = long long;
int n, m;
int a[100100], b[100100];
int dp[100100][100100];
#define endl "\n";
int rec(int i, int j)
{
    if (i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    ans = max(ans, rec(i + 1, j));
    ans = max(ans, rec(i, j + 1));
    if (a[i] == b[j])
    {
        ans = max(ans, rec(i + 1, j + 1) + 1);
    }

    return dp[i][j] = ans;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
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