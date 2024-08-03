#include <bits/stdc++.h>
using namespace std;
using lli = long long;
#define endl "\n"

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = 0;
    while (l != n)
    {
        if (s[l] != '?')
        {
            l++;
            r++;
            continue;
        }
        if (l != 0 && l != n - 1)
        {
            char prev = s[l - 1];
            while (r < n && s[r] == '?')
            {
                r++;
            }
            if (r == n)
            {

                while (l != n)
                {
                    s[l] = '1';
                    l++;
                }
            }
            else
            {

                char next = s[r];
                while (l != r)
                {
                    if (next == prev)
                    {
                        s[l] = next;
                    }
                    else
                    {
                        s[l] = '0';
                    }
                    l++;
                }
            }
            continue;
        }
        if (l == 0)
        {
            s[l] = '0';
            l++;
            r++;
            continue;
        }
        if (l == n - 1)
        {
            s[l] = '1';
            l++;
            r++;
            continue;
        }
    }
    cout << s << endl;
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