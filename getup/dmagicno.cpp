// Write your code here
// have a state
// dp(level, tl, th, 0/1/2)

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
string a, b;
int mod = 1e9 + 7;
int m, d;
int dp[2001][2][2][2001];
int ndig;
int rec(int level, int tl, int th, int mmod)
{
    if (level == ndig)
    {
        if (mmod == 0)
            return 1;
        else
            return 0;
    }
    if (dp[level][tl][th][mmod] != -1)
    {
        return dp[level][tl][th][mmod];
    }
    int ans = 0;
    bool iseven = false;
    if (((level + 1) % 2 == 0))
        iseven = true;
    // i think the original question meant that the even positions are to be counted
    // from the most significant digit. so lets say a number is 4123.... so '1' and '3' and so on are in the even positions (we are not counting the even positions
    // in the decimal sense.)
    int lo = tl ? a[level] - '0' : 0, hi = th ? b[level] - '0' : 9;

    for (int i = lo; i <= hi; i++)
    {
        if (!iseven && i == d)
            continue;
        if (iseven && i != d)
            continue;
        int ntl = tl, nth = th;
        if (i == lo && tl == 1)
        {
            ntl = 1;
            if (lo != hi)
                nth = 0;
            ans += rec(level + 1, ntl, nth, (mmod * 10 + i) % m);
            ans %= mod;
        }
        else if (i == hi && th == 1)
        {
            nth = 1;
            if (lo != hi)
                ntl = 0;
            ans += rec(level + 1, ntl, nth, (mmod * 10 + i) % m);
            ans %= mod;
        }
        else
        {
            ntl = 0, nth = 0;
            ans += rec(level + 1, ntl, nth, (mmod * 10 + i) % m);
            ans %= mod;
        }
    }

    return dp[level][tl][th][mmod] = ans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> m >> d;
        cin >> a;
        cin >> b;
        ndig = a.size();
        cout << rec(0, 1, 1, 0) << endl;
    }
}