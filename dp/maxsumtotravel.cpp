#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
int n, m;
int arr[1001][1001];
int dp[1001][1001];
int done[1001][1001];
int rec(int r, int c)
{
    if (level < 0)
        return -1e9;
    int ans = 0;
    if (done[r][c])
    {
        return dp[r][c];
    }
    if (c != 0)
    {
        ans = max(rec(r, c - 1) + arr[r][c], ans);
    }
    if (r != 0)
    {
        ans = max(rec(r - 1, c) + arr[r][c], ans);
    }
    done[r][c] = 1;
    return dp[r][c] = ans;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            done[i][j] = 0;
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