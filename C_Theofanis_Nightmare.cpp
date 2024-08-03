#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
// make three arrays one given, one prefix, and one for coef
void solve()
{
    int n;
    cin >> n;
    vector<lli> arr(n);
    vector<lli> pfx(n + 1);
    pfx[0] = 0;
    vector<lli> coef(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pfx[i + 1] = arr[i] + pfx[i];
    }
    lli curr = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - 1 == 0)
        {
            curr++;
            coef[i - 1] = curr;
            continue;
        }
        if (pfx[n] - pfx[i - 1] > 0)
        {
            curr++;
            coef[i - 1] = curr;
        }
        else
        {
            coef[i - 1] = curr;
        }
    }
    lli ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += coef[i] * arr[i];
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