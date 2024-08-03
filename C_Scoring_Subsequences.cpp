#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = 0, end = 0;
    ans[0] = arr[0];
    int score = arr[0];
    end++;
    cout << 1 << " "; // for the first case we will have only 1 element.

    for (end; end < n; end++)
    {
        int len = end - start + 1;
        while (len > arr[start])
        {
            start++;
            len--;
        }
        cout << len << " ";
    }
    cout << endl;
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