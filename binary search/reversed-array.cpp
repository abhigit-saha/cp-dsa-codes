#include <bits/stdc++.h>

using namespace std;

using lli = long long;
int arr[100100];
int check(int mid)
{
    if (arr[mid] < arr[0])
        return 1;
    else
        return 0;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = 0, high = n - 1, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(mid) == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
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