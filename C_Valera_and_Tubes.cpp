#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int cellCount = n * m / k;
    int counter = 0;
    int kref = k;
    kref -= 1; // since should be executed k times, we need k executions.
    // for the first one
    cout << cellCount << " ";

    for (int j = 1; j <= n; j++)
    {
        if (j % 2 == 1)
        {

            for (int i = 1; i <= m; i++)
            {
                if (counter == cellCount && kref > 0)
                {

                    if (kref == 1)
                    {
                        cout << endl;
                        cout << n * m - cellCount * (k - 1) << " ";
                        kref--;
                    }
                    else
                    {
                        cout << endl;
                        cout << cellCount << " ";
                        kref--;
                    }
                    counter = 0;
                }

                cout << j << ' ' << i << " ";
                counter++;
            }
        }
        else
        {
            for (int i = m; i >= 1; i--)
            {
                if (counter == cellCount && kref > 0)
                {

                    if (kref == 1)
                    {
                        cout << endl;
                        cout << n * m - cellCount * (k - 1) << " ";
                        kref--;
                    }
                    else
                    {
                        cout << endl;
                        cout << cellCount << " ";
                        kref--;
                    }
                    counter = 0;
                }

                cout << j << " " << i << " ";
                counter++;
            }
        }
    }
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