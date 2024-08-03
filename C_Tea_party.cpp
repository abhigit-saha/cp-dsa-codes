#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{
    lli n, w;
    cin >> n >> w;
    vector<lli> arr(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<lli> ans(n);
    for (lli i = 0; i < n; i++)
    {
        lli ansEl = arr[i] % 2 == 0 ? arr[i] / 2 : arr[i] / 2 + 1;
        ans[i] = ansEl;
        w -= ansEl;
    }
    // cout << "ans array: " << endl;
    // for (auto el : ans)
    // {
    //     cout << el << " ";
    // }
    cout << endl;
    if (w < 0)
    {
        cout << -1 << endl;
        return;
    }
    if (w == 0)
    {
        for (auto el : ans)
        {
            cout << el << " ";
        }
        cout << endl;
        return;
    }
    // w>0;
    vector<pair<lli, lli>> temp(n);
    for (lli i = 0; i < n; i++)
    {

        temp[i] = {i, ans[i]};
    }

    sort(temp.begin(), temp.end(), [](pair<lli, lli> a, pair<lli, lli> b)
         { return a.second < b.second; });
    // for (auto el : temp)
    // {
    //     cout << el.first << " " << el.second << endl;
    // }
    //  now starting from the last fill the glasses to the brim
    for (lli i = n - 1; i >= 0; i--)
    {

        // cout << "w" << w << " " << "arr[i] - temp[i].second" << arr[i] - temp[i].second << endl;
        // temp[i].second = w >= arr[i] - temp[i].second ? arr[i] : temp[i].second + w;
        // w -= arr[i] - temp[i].second;
        // cout << "w after" << w << endl;
        // if (w <= 0)
        // {
        //     break;
        // }
        if (w >= arr[i] - temp[i].second)
        {
            // cout << 'w' << w << endl;
            // cout << "----" << arr[i] - temp[i].second << "----" << endl;
            cout << arr[i] - temp[i].second << endl;
            temp[i].second = arr[i];
            w -= arr[i] - temp[i].second;
            if (w == 0)
            {
                break;
            }
        }
        else
        {

            temp[i].second += w;
            break;
        }
    }
    // for (auto el : temp)
    // {
    //     cout << el.first << " " << el.second << endl;
    // }
    sort(temp.begin(), temp.end(), [](pair<lli, lli> a, pair<lli, lli> b)
         { return a.first < a.second; });
    for (auto el : temp)
    {
        cout << el.second << " ";
    }
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t;cin>>t;while(t--)
    solve();
    return 0;
}