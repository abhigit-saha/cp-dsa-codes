#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    // make an array of servers with arr[i] representing time when it will be free.
    lli n;
    cin >> n;

    vector<lli> arr(n + 1);
    lli q;
    cin >> q;
    while (q--)
    {
        lli t, k, d;
        cin >> t >> k >> d;
        vector<lli> smallestFreeServers;
        for (lli i = 1; i <= n; i++)
        {
            if (arr[i] <= t)
            {
                // make an array of the smallest indices of the servers
                // which are free.
                smallestFreeServers.push_back(i);
            }
            if (smallestFreeServers.size() >= k)
            {
                break;
            }
        }
        lli sum = 0;

        if (smallestFreeServers.size() == k)
        {
            for (lli i = 0; i < smallestFreeServers.size(); i++)
            {
                arr[smallestFreeServers[i]] = t + d;
                sum += smallestFreeServers[i];
            }
            cout << sum << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t;cin>>t;while(t--)
    solve();
    return 0;
}