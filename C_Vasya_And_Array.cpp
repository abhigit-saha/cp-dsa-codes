#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define F first
#define S second

signed main()
{
    int t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> q1, q2;
        bool possible = true;
        vector<int> arr(n + 1), diff(n + 1, -1);
        for (int i = 0; i < m; i++)
        {
            int ty;
            cin >> ty;
            int l, r;
            cin >> l >> r;
            if (ty == 1)
            {

                q1.push_back({l, r});
            }
            else
            {
                q2.push_back({l, r});
            }
        }

        for (auto q : q1)
        {
            for (int i = q.F; i < q.S; i++)
            {
                diff[i] = 0;
            }
        }
        arr[1] = n;
        for (int i = 2; i <= n; i++)
        {
            arr[i] = diff[i - 1] + arr[i - 1];
        }
        for (auto q : q2)
        {
            bool p = false;
            int curmax = arr[q.F]; 
            for (int i = q.F + 1; i <= q.S; i++)
            {
                if (arr[i] < curmax)
                {
                    p = true;
                    break;
                }
                else
                    curmax = arr[i];
            }
            if (!p)
            {
                possible = false;
                break;
            }
        }
        if (!possible)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}