#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    lli n;
    cin >> n;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<lli> ans(n);

    if (n % 2 == 0)
    {
        lli pos = 0;
        for (lli i = 0; i <= n / 2 - 1; i++)
        {
            ans[pos] = arr[i];
            pos += 2;
        }
        pos = 1;
        for (lli i = n / 2; i <= n - 1; i++)
        {
            ans[pos] = arr[i];
            pos += 2;
        }
    }
    else
    {
        cout << "NO" << endl;
        return;
    }

    // checking if valid

    bool valid = true;
    for (lli i = 0; i < n; i++)
    {
        lli temp[3] = {ans[i], ans[(i - 1 + n) % n], ans[(i + 1 + n) % n]};
        sort(temp, temp + 3);
        if (temp[1] == ans[i])
        {
            valid = false;
        }
    }
    if (!valid)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (lli i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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