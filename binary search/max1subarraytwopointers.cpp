#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0, r = n - 1;
    int k;
    cin >> k;
    int curr = 0;
    stack<int> zeros;
    int ans = 0;
    while (r != l)
    {
        ans = max(ans, l - r + 1);
        if (curr == k)
        {
            l = zeros.top() + 1;
            zeros.pop();
            curr--;
            r++;
            continue;
        }
        if (arr[r] == 0)
        {
            zeros.push(r);
            curr++;
            r++;
        }
        else
        {
            r++;
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