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

    map<int, int> mp;
    int l = 0, ans = 0;

    for (int r = 0; r < n; r++)
    {
        if (mp.find(arr[r]) == mp.end() || mp[arr[r]] < l)
        {
            mp[arr[r]] = r;
        }
        else
        {
            int idx = mp[arr[r]];

            while (l < idx)
            {
                l++;
            }
            l++;
            mp[arr[r]] = r;
        }
        int sz = r - l + 1;
        ans = max(ans, sz);
    }

    cout << ans << endl;
}