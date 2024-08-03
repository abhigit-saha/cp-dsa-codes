#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    map<char, int> mp;
    mp['A'] = 0;
    mp['B'] = 0;
    mp['C'] = 0;
    mp['D'] = 0;
    mp['E'] = 0;
    mp['F'] = 0;
    mp['G'] = 0;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    int ans = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->second < m)
        {
            ans += (m - it->second);
        }
    }
    cout << ans << endl;
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