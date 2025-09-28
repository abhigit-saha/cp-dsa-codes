#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int dp[41][41][41];
string a, b;
int n;
int rec(int l, int r, int i)
{

    int j = i + r - l;
    if (l == r)
    {
        return a[l] == b[i];
    }
    if (dp[l][r][i] != -1)
        return dp[l][r][i];

    int ans = 0;
    for (int k = l; k < r; k++)
    {
        int sz = k - l + 1;
        ans |= (rec(l, k, i) & rec(k + 1, r, i+sz));
        ans |= (rec(l, k, j - sz + 1) & rec(k + 1, r, i));
    }

    return dp[l][r][i] = ans;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> a >> b;
        n = a.size();
        int ans = rec(0, n - 1, 0);
        cout << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}