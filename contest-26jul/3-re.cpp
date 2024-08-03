#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> mp1(n + 1, vector<int>(26));
    vector<vector<int>> mp2(n + 1, vector<int>(26));
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < 26; i++)
    {
        mp1[0][i] = 0;
        mp2[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        mp1[i] = mp1[i - 1];
        mp2[i] = mp2[i - 1];
        mp1[i][s1[i - 1] - 'a']++;
        mp2[i][s2[i - 1] - 'a']++;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        for (char i = 1; i <= 26; i++)
        {
            ans += abs(mp1[r][i - 1] - mp1[l - 1][i - 1] - (mp2[r][i - 1] - mp2[l - 1][i - 1]));
        }

        cout << ans / 2 << endl;
    }
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