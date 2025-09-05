#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int arr[200100];
int dp[200100];
int n;
int rec(int level)
{
    if (level == n)
    {
        return 0;
    }
    if (level > n)
        return 1e9;

    if (dp[level] != -1)
        return dp[level];

    int ans = rec(level + arr[level] + 1);

    ans = min(ans, rec(level + 1) + 1);

    return dp[level] = ans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp)); 

        cout << rec(0) << endl;
    }
}