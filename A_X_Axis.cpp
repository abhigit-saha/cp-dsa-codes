#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << arr[2] - arr[0] << endl;
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