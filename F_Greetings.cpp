#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define S second
#define F first

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ordered_set removed;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].S >> arr[i].F;
        }
        sort(arr.begin(), arr.end());

        long long ans = 0;
        for (auto p : arr)
        {
            ans += removed.size() - removed.order_of_key(p.second);

            removed.insert(p.second);
        }

        cout << ans << endl;
    }
    return 0;
}