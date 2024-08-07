#include <bits/stdc++.h>
using namespace std;
using lli = long long;
#define endl "\n";
int n, maxW;
int w[100], v[100];
int rec(int level, int weight, int value)
{ // returns max summation of weights you can take from (level..n-1)
    if (level == n)
    {
        return value;
    }
    int ans = rec(level + 1, weight, value);
    if (weight + w[level] <= maxW)
    {
        ans = max(ans, rec(level + 1, weight + w[level], value + v[level]));
    }
    return ans;
}
void solve()
{
    cin >> n >> maxW;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    // for (auto el : w)
    // {
    // cout << el << " ";
    // }
    cout << rec(0, 0, 0) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}