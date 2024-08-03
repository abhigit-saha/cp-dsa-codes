#include <bits/stdc++.h>

using namespace std;

using lli = long long;
struct frac
{
    pair<int, int> pr;
    frac(int b, int a)
    {
        pr = {b, a};
        reduce();
    }

    void reduce()
    {
        // handle negative deon
        if (pr.second < 0)
        {
            pr.second *= -1;
            pr.first *= -1;
        }
        // handle zeros
        if (pr.second == 0 && pr.first != 0) // undef values standardized to 1/0
        {
            pr.first = 1;
        }
        else if (pr.first == 0) // 0 standardized as 0/1
        {
            pr.second = 1;
        }
        else
        {
            pr.first /= __gcd(abs(pr.first), abs(pr.second));
            pr.second /= __gcd(abs(pr.first), abs(pr.second));
        }
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<long double> a(n), b(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && b[i] != 0)
        {
            // ignore
            continue;
        }
        else
        {
            frac f(b[i], a[i]);
            mp[f.pr]++;
            cout << f.pr.first << " " << f.pr.second << endl;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        ans = max(ans, it->second);
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