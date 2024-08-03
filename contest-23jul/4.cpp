#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    lli n;
    cin >> n;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    lli greatest = 0;
    lli ans = 0;
    for (lli i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (i != n - 1)
            {
                arr[i + 1] /= arr[i];
            }
            greatest = arr[i];

            continue;
        }
        if (arr[i] >= greatest)
        {
            arr[i] /= greatest;
            greatest = arr[i];
        }
        else
        {
            while (arr[i] < greatest)
            {
                arr[i] = arr[i] * arr[i];
                ans++;
            }
            arr[i] = 1;
            if (i != n - 1)
            {
                arr[i + 1] /= arr[i];
            }

            greatest = arr[i];
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}