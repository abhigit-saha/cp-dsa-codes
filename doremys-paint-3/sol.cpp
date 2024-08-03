#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr;
    map<int, int> nbors;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        arr.emplace_back(el);
        nbors[el]++;
    }
    if (nbors.size() > 2)
    {
        cout << "No" << endl;
        return;
    }

    if (nbors.size() == 1)
    {
        cout << "Yes" << endl;
        return;
    }

    set<int> st;
    auto it = nbors.begin();
    int fOne = it->second;
    it++;
    int fTwo = it->second;
    if (n % 2 == 0 && fOne == fTwo)
    {
        cout << "Yes" << endl;
    }
    else if (n % 2 == 1 && abs(fOne - fTwo) == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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