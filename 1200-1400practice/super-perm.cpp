#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    set<int> st;
    vector<int> ans(n + 1);
    ans[1] = n;
    for (int i = 1; i <= n; i++)
    {
        st.insert(i);
    }
    int small = 1, large = n - 1, prev = ans[1]; // small is not 0 because we already added it
    lli sum = n;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            if (st.find((small - prev + n) % n) == st.end())
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                st.erase((small - prev + n) % n);
                ans[i] = (small - prev + n) % n;
                sum += ans[i];
                prev = sum % n;
                small++;
            }
        }
        else
        {
            if (st.find((large - prev + n) % n) == st.end())
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                st.erase((large - prev + n) % n);
                ans[i] = (large - prev + n) % n;
                sum += ans[i];
                prev = sum % n;
                large--;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
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