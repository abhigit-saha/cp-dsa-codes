#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int minneg = -1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        minneg = max(minneg, arr[i]);
    }
    bool ispos = false;
    int ans = -1e9, sum = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, sum);
        sum += arr[i];
        if (sum >= 0)
            ispos = true;
        ans = max(ans, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    if (!ispos)
    {
        cout << minneg << endl;
    }
    else
    {
        cout << ans << endl;
    }
}