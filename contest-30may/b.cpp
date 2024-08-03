#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

using lli = long long;

void solve()
{
    lli n;
    cin >> n;
    vector<lli> a, b;
    for (int i = 0; i < n; i++)
    {
        lli el;
        cin >> el;
        a.emplace_back(el);
    }
    for (int i = 0; i < n + 1; i++)
    {
        lli el;
        cin >> el;
        b.emplace_back(el);
    }
    lli ans = 0;
    bool shortcut = false;
    lli l = b[n];
    lli mindiffwithl = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i] - b[i]);
        mindiffwithl = min(mindiffwithl, abs(a[i] - l));
        mindiffwithl = min(mindiffwithl, abs(b[i] - l));

        if ((a[i] >= l && b[i] <= l) || (a[i] <= l && b[i] >= l))
        {
            shortcut = true;
        }
    }
    if (shortcut)
    {
        ans += 1;
    }
    else
    {
        ans += 1;
        ans += mindiffwithl;
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