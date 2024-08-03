#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    lli n, w;
    cin >> n >> w;
    vector<lli> capacity(n);
    vector<pair<lli, lli>> arr(n);
    for (lli i = 0; i < n; i++)
    {
        lli cap;
        cin >> cap;
        capacity[i] = cap;
        lli req = ceil((double)cap / 2);
        arr[i] = {i, req};
        w -= req;
    }

    if (w < 0)
    {
        cout << -1 << endl;
        return;
    }
    sort(arr.begin(), arr.end(), [capacity](pair<lli, lli> a, pair<lli, lli> b)
         { return capacity[a.first] > capacity[b.first]; });
    for (auto &el : arr)
    {
        lli alreadyFilled = el.second;

        el.second += min(w, capacity[el.first] - alreadyFilled);
        w -= min(w, (capacity[el.first] - alreadyFilled));
        if (w == 0)
        {
            break;
        }
    }

    sort(arr.begin(), arr.end(), [](pair<lli, lli> a, pair<lli, lli> b)
         { return a.first < b.first; });
    for (auto el : arr)
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
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}