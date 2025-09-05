#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> h(n, vector<char>(m - 1, '.')), v(n - 1, vector<char>(m, '.'));
        if (k >= n + m - 2 && k % 2 == (n + m) % 2)
        {
            cout << "YES" << endl;
            int rem = k - (n + m - 2);
            string col = "RB";

            int cur = 0;
            function<void(int, int, int, int)> p = [&](int i, int j, int t, int sm)
            {
                if (i == n - 1 && j == m - 1)
                    return;

                if (i == n - 1)
                {
                    return p(i, j + 1, 1 - t, 1);
                }
                else if (j == m - 1)
                {
                    return p(i + 1, j, 1 - t, 1);
                }

                if (t)
                {
                    h[i][j] = col[cur];
                    cur = 1 - cur;
                    if (sm)
                        return p(i, j + 1, t, sm);
                    return p(i, j + 1, 0, sm);
                }
                else
                {
                    v[i][j] = col[cur];
                    cur = 1 - cur;
                    if (sm)
                        return p(i, j + 1, t, sm);
                    return p(i + 1, j, 1, sm);
                }
            };
            if (rem % 4 == 0)
            { 

            }
            else
            {

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m - 1; j++)
                    {
                        cout << h[i][j] << " ";
                    }
                    cout << endl;
                }

                for (int i = 0; i < n - 1; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        cout << v[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}