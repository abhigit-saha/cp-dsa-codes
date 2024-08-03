#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{
    lli n, m;
    cin >> n >> m;
    vector<lli> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    lli maxFlowers = 0;
    int l = 0, r = 0;
    set<lli> st;
    while (l != n)
    {

        if (arr[r] - arr[l] <= 1 && m - arr[r] >= 0)
        {

            m -= arr[r];
            maxFlowers += arr[r];
            if (r == n - 1)
            {
                st.insert(maxFlowers);
                break;
            }
            r++;
        }
        // else if (arr[r] - arr[l] > 1)
        // {
        //     st.insert(maxFlowers);
        //     maxFlowers = 0;
        //     l = r;
        //     l++;
        //     r++;
        // }
        else
        {
            st.insert(maxFlowers);
            m += arr[l];
            maxFlowers -= arr[l];
            l++;
        }
    }
    cout << *st.rbegin() << endl;
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