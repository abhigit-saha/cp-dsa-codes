#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

using lli = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        arr.emplace_back(el);
    }

    vector<int> oldarr = arr;
    sort(arr.begin(), arr.end());
    bool sorted = arr == oldarr;
    if (sorted)
    {
        cout << "YES" << endl;
        return;
    }
    if (k >= 2)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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