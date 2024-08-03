#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    int x = 0, count = 0;
    while (l < r)
    {
        if (r == l)
        {
            lli var = (arr[l] + x + 1) / 2;

            count += var;
            // now x>=arr[l];
            arr[l] = 0;
            // one move to finish it.
            count++;
        }
        if (x + arr[l] < arr[r])
        {
            x += arr[l];
            arr[l] = 0;
            count += arr[l];
            l++;
        }
        else
        {
            arr[l] -= arr[r] - x;
            x = 0;
            arr[r] = 0;
            count += arr[r] - x + 1;
            r--; //+1 for the special move.
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << count << endl;
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