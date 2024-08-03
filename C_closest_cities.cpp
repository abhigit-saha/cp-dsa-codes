#include <bits/stdc++.h>
#define endl '\n';
using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;

    int fwdAns[n + 1]; // cost needed to go to the index from the start.
    int bwdAns[n + 1];
    fwdAns[1] = 0;
    fwdAns[2] = 1;
    bwdAns[n] = 0;
    bwdAns[n - 1] = 1;
    for (int i = 2; i < n; i++)
    {

        // if distance with the previous element is greater than the next element
        // then the next element is the closest element so only add 1 to the ans
        if (abs(arr[i + 1] - arr[i]) < abs(arr[i - 1] - arr[i]))
        {
            fwdAns[i + 1] = fwdAns[i] + 1;
        }
        else
        {
            fwdAns[i + 1] = fwdAns[i] + abs(arr[i + 1] - arr[i]);
        }
    }
    for (int i = n - 1; i > 1; i--)
    {
        if (abs(arr[i - 1] - arr[i]) < abs(arr[i + 1] - arr[i]))
        {
            bwdAns[i - 1] = bwdAns[i] + 1;
        }
        else
        {
            bwdAns[i - 1] = bwdAns[i] + abs(arr[i - 1] - arr[i]);
        }
    }

    while (m--)
    {
        int ans = 0;
        int x, y;
        cin >> x >> y;
        if (y > x)
        {
            cout << fwdAns[y] - fwdAns[x] << endl;
        }
        else
        {
            cout << bwdAns[y] - bwdAns[x] << endl;
        }
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