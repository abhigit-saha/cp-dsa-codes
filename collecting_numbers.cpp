#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int el;
        cin >> el;
        mp[el] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (mp[i - 1] > mp[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
}