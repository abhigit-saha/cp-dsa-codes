#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
int given[3];
int price[3];
int req[3];
lli r;
int check(lli mid)
{
    lli costNeeded = 0;
    for (int i = 0; i < 3; i++)
    {
        lli incr;
        if (req[i] * mid * price[i] - given[i] * price[i] >= 0)
        {
            incr = req[i] * mid * price[i] - given[i] * price[i];
        }
        else
        {
            incr = 0;
        }
        costNeeded += incr;
    }
    if (costNeeded <= r)
    {
        return 1;
    }
    return 0;
}
void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
        {
            req[0]++;
        }
        if (s[i] == 'S')
        {
            req[1]++;
        }
        if (s[i] == 'C')
        {
            req[2]++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        0 cin >> given[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> price[i];
    }
    cin >> r;
    lli lo = 0, hi = 1e15, ans = 0;
    while (lo <= hi)
    {
        lli mid = lo + (hi - lo) / 2;
        if (check(mid) == 1)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
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
