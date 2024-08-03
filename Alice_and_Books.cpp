#include <bits/stdc++.h>

using namespace std;

using lli = long long;
// note: imo monotone concept (think bars)
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    multiset<int> mst;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mst.insert(arr[i]);
        int k = i;
        while (distance(upper_bound(mst.begin(), mst.end(), arr[k]), lower_bound(mst.begin(), mst.end(), arr[k])) != k)
        {
            k--;
        }
        cout << k << endl;
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