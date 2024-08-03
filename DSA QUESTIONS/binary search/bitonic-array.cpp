#include <bits/stdc++.h>

using namespace std;

using lli = long long;
int arr[100100];
int n;
int check(int mid)
{
    if (mid == n - 1)
        return 1;
    if (arr[mid] > arr[mid + 1])
        return 1;
    else
        return 0;
}
void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int low = 0, high = n - 1, peak = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(mid) == 1)
        {
            peak = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        int low = 0, high = peak - 1, ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                cout << mid + 1 << " ";
                break;
            }
            if (arr[mid] > x)
            {

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        low = peak;
        high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                cout << mid + 1 << " ";
                break;
            }
            if (arr[mid] < x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << endl;
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