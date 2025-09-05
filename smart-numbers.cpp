#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int a, b;
int alevel;

unordered_map<int, int> dp[2][2][31];
int rec(int level, int tl, int th, int sum)
{
    int ans = 0;
    int low = 0, hi = 9;
    if (level == alevel - 1)
    {
        if (sum == 0)
            return 1;
        return 0;
    }

    if (dp[tl][th][level][sum] != -1)
        return dp[tl][th][level][sum];
    if (tl)
    {
        low = ((a >> level) & 1);
    }
    if (th)
    {
        hi = ((b >> level) & 1);
    }
    for (int dig = low; dig <= hi; dig++)
    {
        if (dig == low && tl)
        {
            ans += (rec(level - 1, 1, th, sum + dig) + rec(level - 1, 1, th, sum - dig));
        }
        else if (dig == hi && th)
        {
            ans += (rec(level - 1, tl, 1, sum + dig) + rec(level - 1, tl, 1, sum - dig));
        }

        else
        {
            ans += (rec(level - 1, tl, th, sum + dig) + rec(level - 1, tl, th, sum - dig));
        }
    }

    return dp[tl][th][level][sum] = ans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}