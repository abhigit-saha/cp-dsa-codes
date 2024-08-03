#include <bits/stdc++.h>

using namespace std;

using lli = long long;

int solve(int n, int l, int r, vector<int> arr)
{
    // lli n, l, r;
    // cin >> n >> l >> r;
    // vector<lli> arr(n);
    lli sum = 0;
    lli ans = 0;
    for (lli i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        if (sum >= l && sum <= r)
        {
            ans++;
            sum = 0;
        }
        else
        {
            if (sum > r)
            {
                if (arr[i] >= l && arr[i] <= r)
                {
                    ans++;
                }
                sum = 0;
            }
        }
    }
    return ans;
}

int solveCorrect(int n, int l, int r, vector<int> arr)
{
    lli ans = 0;
    lli sum = 0;
    vector<lli> pfx;
    pfx[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        pfx[i] = pfx[i - 1] + arr[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (pfx[j] - pfx[i] + arr[i] >= l && pfx[j] - pfx[i] + arr[i] <= r)
            {
                ans++;
                i = j;
            }
        }
    }
    cout << sum << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}