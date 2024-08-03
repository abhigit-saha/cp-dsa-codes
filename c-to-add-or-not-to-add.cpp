#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), [](int a, int b, int c)
         { return arr[b] - arr[a] <= arr[c] - arr[b]; });
    if (n == 1)
    {
        cout << 1 << " " << arr[0] << endl;
        return;
    }
    int freq = n, ans = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (k - (arr[i] -))
        }
    }
    cout << freq << " " << ans << endl;
    return;
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