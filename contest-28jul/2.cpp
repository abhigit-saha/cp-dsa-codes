#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<lli> arr(n, 0);
    vector<lli> given(n - 1);
    bool doable = true;
    lli maxEl = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> given[i];
        maxEl = max(maxEl, given[i]);
    }
    for (int i = 0; i < n; i++)
    {
        // lli el;
        // cin >> el;

        // first el is the same
        // if (i == 0)
        // {
        //     arr[i] = given[i];
        //     continue;
        // }
        // // second el is the 111....
        if (i == 0)
        {
            arr[i] = given[i];
            continue;
        }
        if (i == 1)
        {
            lli temp = maxEl;

            int size = 0;
            while (temp)
            {
                arr[i] += (1 << size);

                size++;
                temp = temp >> 1;
            }
            continue;
        }
        lli temp = maxEl;

        int size = 0;
        while (temp)
        {
            arr[i] += (1 << size);

            size++;
            temp = temp >> 1;
        }

        if (i != 0)
        {
            for (int k = 0; k < 30; k++)
            {
                if ((given[i - 1] >> k) % 2 == 0 && (arr[i - 1] >> k) % 2 == 1)
                {
                    arr[i] -= 1 << k;
                }
                else if ((given[i - 1] >> k) % 2 == 1 && (arr[i - 1] >> k) % 2 == 0)
                {
                    doable = false;
                    break;
                }
            }
        }

        // for (int k = 0; k < 30; k++)
        // {

        //     // cout << (el >> k) % 2 << " " << (arr[i] >> k) % 2 << endl;

        //     if ((given[i - 1] >> k) % 2 == 1 && (arr[i - 1] >> k) % 2 == 1)
        //     {
        //         arr[i] += (1 << k);
        //     }

        //     // else if ((el >> k) % 2 == 1 && (arr[i - 1] >> k) % 2 == 0)
        //     // {
        //     //     doable = false;
        //     // }
        // }
    }
    if (doable)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
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