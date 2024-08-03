#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    for (int i = 1; i <= 100; i++)
    {
        cout << i << " : " << (i * (i + 1) / 2) % i << endl;
    }
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