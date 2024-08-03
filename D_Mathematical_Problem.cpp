#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int twoDig = 0;
    bool zero = false;
    // cout << s << endl;
    for (int i = 0; i < n - 1; i++)
    {
        twoDig = min((s[i] - '9') * 10 + s[i + 1] - '9', twoDig);
    }
    for (int i = 0; i < n - 1; i++)
    {
        // if (s[i] == '0' && i != 1 && n != 3)
        // {
        //     ans = 0;
        //     zero = true;
        //     break;
        // }

        ans += ctoi(s[i]);
    }
    // cout << "TwoDig " << twoDig << endl;
    // if (zero)
    // {
    //     cout << ans << endl;
    // }
    // else
    // {
    //     if (n - 2 == 0)
    //     {
    //         cout << twoDig << endl;
    //     }
    //     else
    //     {
    //         int var = twoDig / 10;
    //         if (var == 1)
    //         {
    //             cout << ans + 10 << endl;
    //         }
    //         else
    //         {
    //             ans += 9 * var;
    //             cout << ans << endl;
    //         }
    //     }
    // }
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