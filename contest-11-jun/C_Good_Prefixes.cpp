#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{
    int n;
    cin >> n;
    vector<lli> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    multiset<double> st;
    lli sum = 0;
    lli ans = 0;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
        sum += arr[i];
        if (st.find((1.0F * sum) / 2) != st.end())
        {
            ans++;
        }
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