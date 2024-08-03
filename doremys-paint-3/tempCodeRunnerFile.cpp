#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr;
    map<int, int> nbors;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        arr.emplace_back(el);
        if (i != 0 && i % 2 == 0)
        {
            if (arr[i] != arr[i - 2])
            {
                cout << "No" << endl;
                return;
            }
        }
        else if (i != 1 && i % 2 == 1)
        {
            if (arr[i] != arr[i - 2])
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