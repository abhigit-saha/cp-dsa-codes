#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxEl = INT_MIN;
    int maxEl2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int sum = maxEl + arr[i];
        maxEl = max(maxEl, arr[i]);
        maxEl2 = max(maxEl2, sum - maxEl);
    }

    cout << maxEl << endl;
    cout << maxEl2 << endl;
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