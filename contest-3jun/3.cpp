#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> st;
    int dcount = 0;
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
            dcount++;
        }
    }
    cin >> m;
    set<int> temp = st;
    if (m < dcount)
    {
        cout << "NO" << endl;
        return;
    }
    vector<int> d(m);
    for (int i = 0; i < m; i++)
    {
        cin >> d[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (st.find(d[i]) == st.end())
        {
            cout << "NO" << endl;
            return;
        }
        temp.erase(d[i]);
    }
    if (temp.empty())
    {

        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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