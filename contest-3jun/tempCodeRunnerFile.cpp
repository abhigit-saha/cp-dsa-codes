#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[i] != b[i])
        {
            st.insert(b[i]);
        }
    }
    cin >> m;
    vector<int> d(m);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        if (st.find(d[i]) == st.end())
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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