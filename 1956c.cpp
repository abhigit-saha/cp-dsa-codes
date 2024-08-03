#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i + 1;
    }
    vector<vector<int>> m(n, vector<int>(n));
    int op1 = 0, op2 = 0;
    for (int i = 0; i < n; i++)
    {
        // for (auto el : perm)
        // {
        //     cout << el << " ";
        // }
        for (int j = 0; j < n; j++)
        {
            m[i][j] = perm[j];
            // cout << perm[j] << " ";
        }
        op1++;
        // cout << endl;
    }
    for (int j = 0; j < n; j++)
    {
        if (j < n / 2)
        {
            for (int i = 0; i < n; i++)
            {
                // cout << perm[i] << " ";
                m[i][j] = perm[i];
            }
            op2++;
            // cout << endl;
        }
    }
    lli sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += m[i][j];
        }
    }
    cout << sum << " " << op1 + op2 << endl;
    for (int i = 0; i < n; i++)
    {
        cout << 1 << " " << i + 1 << " ";
        for (auto el : perm)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    for (int j = 0; j < n; j++)
    {
        if (j < n / 2)
        {

            cout << 2 << " " << j + 1 << " ";
            for (auto el : perm)
            {
                cout << el << " ";
            }
            cout << endl;
        }
    }
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