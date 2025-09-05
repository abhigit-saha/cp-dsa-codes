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

        int n, k;
        cin >> n >> k;
        int lo = 1, hi = 1e13, ans = 1;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // for (int i = 1; i <= 100; i++)
        // {
        //     int pref = upper_bound(a.begin(), a.end(), i) - a.begin();
        //     cout << "pref " << i << " : " << pref << endl;
        // }

        if (a[0] != 1)
        {
            cout << 1 << endl;
            continue;
        }

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            int curpos = mid;

            int days = 0;
            while (curpos >= 1)
            {
                int pref = upper_bound(a.begin(), a.end(), curpos) - a.begin();
                int times = 1 + (curpos - a[pref - 1]) / pref;
                days += times;
                curpos -= pref * times;
            }

            if (days > k)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}