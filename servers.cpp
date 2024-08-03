#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    int lastTime = 0;
    while (q--)
    {
        int t, k, d;
        cin >> t >> k >> d;
        int l = 0, r = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            arr[i] = max(0, arr[i] - (t - lastTime));
            if (arr[i] > 0)
            {
                l = r = i + 1;
            }
            else
            {
                ++r;
                if (r - l == k)
                {
                    for (int j = l; j < r; ++j)
                    {
                        ans += j + 1;
                    }
                    break;
                }
            }
        }
        if (ans == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
            for (int i = l; i < r; ++i)
            {
                arr[i] = d;
            }
        }
        lastTime = t;
    }
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