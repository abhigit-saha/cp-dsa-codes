#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

using lli = long long;

lli gcd(lli a, lli b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
void solve()
{
    int n;
    cin >> n;
    vector<lli> arr;
    vector<lli> b;

    for (int i = 0; i < n; i++)
    {
        lli el;
        cin >> el;
        arr.emplace_back(el);
    }
    sort(arr.begin(), arr.end());
    lli min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] % min != 0)
        {
            b.emplace_back(arr[i]);
        }
    }

    if (b.size() == 0)
    {
        cout << "Yes" << endl;
        return;
    }
    else
    {
        for (int i = 1; i < b.size(); i++)
        {
            if (b[i] % b[0] != 0)
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
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