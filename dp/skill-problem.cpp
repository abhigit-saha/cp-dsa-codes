#include <bits/stdc++.h>

using namespace std;

using lli = long long;
int n, maxTime, maxTaken;
int t[1001], s[1001], taken[1001];
bool check(int level)
{
    int timetaken = 0, takenTillNow = 0;
    for (int i = 0; i < level; i++)
    {
        if (taken[level])
        {
            timetaken += t[i];
            takenTillNow++;
        }
    }
    timetaken += s[level];
    takenTillNow++;
    if (timetaken <= maxTime && takenTillNow <= maxTaken)
    {
        return true;
    }
    return false;
}
int rec(int level)
{

    // pruning

    // basecase
    if (level == n)
        return 0;

    // case 1: don't take this current one
    int ans = rec(level + 1);
    // case 2: take this current one
    if (check(level))
    {
        taken[level] = 1;
        ans = max(ans, s[level] + rec(level + 1));
        taken[level] = 0;
    }

    return ans;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> maxTime >> maxTaken;
    cout << rec(0) << endl;
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