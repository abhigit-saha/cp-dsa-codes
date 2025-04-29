#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    multiset<int> mst;
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mst.find(arr[i]) == mst.end())
        {
            mst.insert(arr[i]);
            int sz = mst.size();
            ans = max(ans, sz);
            mp[arr[i]]++;
        }
        else
        {
            if (mp[arr[i]] == 1)
            {
                mp[arr[i]]++;
            }
            else
            {
                mst.clear();
                mp.clear();
                mst.insert(arr[i]);
                mp[arr[i]]++;
            }
        }
    }
    cout << ans << endl;
}