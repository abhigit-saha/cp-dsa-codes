#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> check = {{0, -1, 1},
                                 {1, 0, -1},
                                 {-1, 0, 1},
                                 {0, 1, -1},
                                 {1, -1, 0},
                                 {-1, 1, 0}};
    vector<int>
        a(n),
        b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        cin >> c[i];
    lli ans = 0;

    for (int i = 0; i < n; i++)
    {

        for (auto el : check)
        {
            bool condition = true;
            for (int j = 0; j < 3; j++)
            {
                if (!(i + el[j] >= 0 && i + el[j] < n))
                {
                    condition = false;
                }
            }
            if (condition)
            {

                ans = max(ans, 1LL * (a[i + el[0]] + b[i + el[1]] + c[i + el[2]]));
                cout << a[i + el[0]] << " " << b[i + el[1]] << " " << c[i + el[2]] << endl;
            }
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