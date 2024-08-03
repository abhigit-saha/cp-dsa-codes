#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> req(3);
    vector<int> have(3);
    vector<int> price(3);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            req[0]++;
        }
        if (s[i] == 'S')
        {
            req[1]++;
        }
        if (s[i] == 'C')
        {
            req[2]++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> have[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> price[i];
    }
    lli r;
    cin >> r;
    cout << "r: " << r << endl;
    int canBuy = INT_MAX;
    int i = 0;
    // while (canBuy != INT_MAX)
    // {
    //     canBuy = INT_MAX;

    //     if (have[i] >= req[i])
    //     {
    //         canBuy = min(have[i] / req[i], canBuy);
    //     }
    //     i++;
    // }
    int passes = 3;
    int boughtTillNow = 0;
    // first making all have[i]=0 ie utilizing our current inventory most effectively.
    while (passes--)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << have[i] << " ";
        }
        cout << endl;
        canBuy = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            if (have[i] >= req[i] && req[i] != 0)
            {
                canBuy = min(have[i] / req[i], canBuy);
            }
        }
        cout << canBuy << endl;
        if (canBuy != INT_MAX)
        {
            for (int i = 0; i < 3; i++)
            {
                if (req[i] == 0)
                    continue;
                if (have[i] < canBuy * req[i])
                {
                    r -= ((req[i] * canBuy - have[i])) * price[i];
                    have[i] = 0;
                }
                else
                {
                    have[i] -= canBuy * req[i];
                }
            }
            if (r >= 0)
            {
                boughtTillNow += canBuy;
            }
        }
        else
        { // all have[i]<req[i];
            for (int i = 0; i < 3; i++)
            {
                if (req[i] == 0)
                    continue;
                r -= (req[i] - have[i]) * price[i];
                have[i] = 0;
            }
            if (r >= 0)
            {
                boughtTillNow += 1;
            }
            break;
        }
    }
    cout << boughtTillNow << endl;
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