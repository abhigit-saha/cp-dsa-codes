#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    string s;
    cin >> s;
    lli n = s.size();
    lli bCnt = 0, sCnt = 0, cCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            bCnt++;
        }
        if (s[i] == 'S')
        {
            sCnt++;
        }
        if (s[i] == 'C')
        {
            cCnt++;
        }
    }
    int a, b, c;
    cin >> a >> b >> c;
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    lli p;
    cin >> p;
    lli ans = (p - (a * p1 + b * p2 + c * p3)) / (bCnt * p1 + sCnt * p2 + cCnt * p3);
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