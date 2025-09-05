#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int dp[200100][2];
vector<int> arr;
int n;
int rec(int level, int turn)
{
    if (level == n)
        return 0;
    if (dp[level][turn] != -1)
        return dp[level][turn];
    int ans = 1e9;
    if (turn == 1)
    {
        // ans = min(rec(1-turn, level+1))
        ans = min(ans, rec(level + 1, 1 - turn));
        if (level + 1 < n)
        {
            ans = min(ans, rec(level + 2, 1 - turn));
        }
    }
    else
    {
        int hard = arr[level] == 1;
        ans = min(ans, rec(level + 1, 1 - turn) + hard);
        if (level + 1 < n)
        {
            int hard2 = arr[level + 1] == 1;
            ans = min(ans, rec(level + 2, 1 - turn) + hard + hard2);
        }
    }
    return dp[level][turn] = ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        arr.clear();
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << rec(0, 0) << endl;
    }
    return 0;
}