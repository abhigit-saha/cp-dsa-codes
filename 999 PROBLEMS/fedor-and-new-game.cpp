#include <bits/stdc++.h>

using namespace std;

using lli = long long;

uint32_t flp2(uint32_t n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n - (n >> 1);
}

int setBits(int n)
{
    int ans = 0;
    while (n)
    {
        n = (n & (n - 1));
        ans++;
    }
    return ans;
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr;
    for (int i = 0; i < m + 1; i++)
    {
        int el;
        cin >> el;
        while (el >= pow(2, n))
        {
            int sub = flp2(el);
            el -= sub;
        }
        arr.emplace_back(el);
        cout << el << endl;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (setBits(arr[m + 1] & arr[i]) <= k)
        {
            cout << (arr[m + 1] & arr[i]) << endl;
            ans++;
        }
    }
    cout << ans << "\n";
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