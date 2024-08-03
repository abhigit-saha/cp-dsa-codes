#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{

    int n, m;
    cin >> n >> m;

    // rem to handle edgecases

    if (!((m >= n - 1) && (2 * (n + 1) >= m)))
    {
        cout << -1 << endl;
        return;
    }

    if (n > m)
    {
        vector<int> arr(2 * n - 1);
        int j = 0;
        while (n--)
        {
            if (j % 2 == 0)
            {
                arr[j] = '0';
                j += 2;
            }
        }
        int i = 1;
        while (m--)
        {
            if (i % 2 == 1)
            {
                arr[i] += '1';
                i = (i + 2);
            }
        }
        string ans;
        for (auto str : arr)
        {
            ans += str;
        }
        cout << ans << endl;
        return;
    }

    vector<string> arr(2 * n + 1);

    int i = 0;
    while (m--)
    {
        if (i % 2 == 0)
        {
            arr[i] += '1';
            i = (i + 2) % (2 * n + 2);
        }
    }

    int j = 1;
    while (n--)
    {
        if (j % 2 == 1)
        {
            arr[j] = '0';
            j += 2;
        }
    }

    string ans;
    for (auto str : arr)
    {
        ans += str;
    }
    cout << ans << endl;
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