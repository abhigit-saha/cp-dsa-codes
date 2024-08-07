#include <bits/stdc++.h>
using namespace std;
using lli = long long;
#define endl "\n" // Removed semicolon
int n;
string ans = "";

void rec(int open, int size)
{
    if (size == n && open == 0)
    {
        cout << ans << "\n";
        return; // Removed ans.pop_back() and moved return
    }
    if (size < n)
    {
        if (open < (n - size))
        {
            ans += "(";
            rec(open + 1, size + 1);
            ans.pop_back();
        }
        if (open > 0)
        {
            ans += ")";
            rec(open - 1, size + 1);
            ans.pop_back();
        }
    }
}

void solve()
{
    cin >> n;
    rec(0, 0);
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