#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> posn;
    for (int i = 0; i < m; i++)
    {
        int el;
        cin >> el;
        posn.insert(el);
    }
    string c;
    cin >> c;

    vector<char> cVector(m);
    for (int i = 0; i < m; i++)
    {
        cVector[i] = c[i];
    }
    sort(cVector.begin(), cVector.end());
    string sortedC;
    for (auto el : cVector)
    {
        sortedC += el;
    }
    int cnter = 0;
    for (auto it = posn.begin(); it != posn.end(); ++it)
    {
        s[*it - 1] = sortedC[cnter];
        cnter++;
    }
    cout << s << endl;
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