#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    set<int> st;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            if (st.find('R') != st.end())
            {
                ans++;
                st.clear();
                st.insert('L');
            }
            else
            {
                st.insert('L');
            }
        }
        else if (s[i] == 'R')
        {
            if (st.find('L') != st.end())
            {
                ans++;
                st.clear();
                st.insert('R');
            }
            else
            {
                st.insert('R');
            }
        }
        else if (s[i] == 'U')
        {
            if (st.find('D') != st.end())
            {
                ans++;
                st.clear();
                st.insert('U');
            }
            else
            {
                st.insert('U');
            }
        }
        else if (s[i] == 'D')
        {
            if (st.find('U') != st.end())
            {
                ans++;
                st.clear();
                st.insert('D');
            }
            else
            {
                st.insert('D');
            }
        }
    }
    cout << ans + 1 << endl;
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