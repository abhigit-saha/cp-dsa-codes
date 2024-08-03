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
    int l = 0, r = s.size() - 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    if (count != 0)
    {
        cout << -1 << endl;
        return;
    }
    // cout << s << endl;
    vector<int> pos;
    while (count <= 300)
    {
        if (l > r)
        {
            break;
        }
        if (s[l] == s[r])
        {
            if (s[l] == '1')
            {
                s = s.substr(0, l) + "01" + s.substr(l, r + 1);
                pos.push_back(l);
                // s  = s(from 0 to l-1(incl)) + 01(l and l+1) + rest. so l'th el is compared, so move to l+1.
            }
            else
            {
                s = s.substr(0, r + 1) + "01" + s.substr(r + 1, s.size() + 1);
                pos.push_back(r + 1);
                // s  = s(from 0 to r(incl)) + 01(r+1 and r+2)
            }
            count++;
        }
        l++;
        r = s.size() - l - 1;
        // we always need to commpare l with this r. (no other r). always always
    }
    if (r > l)
    {
        cout << -1 << endl;
        return;
    }
    cout << count << endl;

    for (int i = 0; i < pos.size(); i++)
    {
        cout << pos[i] << " ";
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