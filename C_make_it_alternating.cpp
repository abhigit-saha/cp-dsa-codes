#include <bits/stdc++.h>

using namespace std;

using lli = long long;
lli mod = 998244353;
lli fact(lli n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return ((n % mod) * (fact(n - 1) % mod)) % mod;
}
void solve()
{
    // define a deletions variable that counts number of deletions needed = 0 (init)
    // define a possibleVariations variable = 1 (init)
    lli deletions = 0, possibleVariations = 1;
    char lastBit = '0';
    string s;
    cin >> s;
    lli currBitDeletions = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (lastBit == s[i] && i != 0)
        {
            currBitDeletions++;
        }
        if ((lastBit != s[i] && i != 0) || (i == n - 1))
        {
            // multiplying act
            deletions += currBitDeletions;

            possibleVariations = (((possibleVariations % mod) * ((currBitDeletions + 1) % mod)) % mod);
            currBitDeletions = 0;
            lastBit = s[i];
        }
        if (i == 0)
        {
            lastBit = s[i];
        }
    }
    cout << deletions << " " << ((possibleVariations % mod) * (fact(deletions) % mod)) % mod << endl;
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