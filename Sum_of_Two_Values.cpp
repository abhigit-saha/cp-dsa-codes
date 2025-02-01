#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main()
{
    int n, x;
    cin >> n >> x;
    multiset<int> st;
    map<int, vector<int>> eltoidx;

    for (int i = 1; i <= n; i++)
    {
        int el;
        cin >> el;
        st.insert(el);
        eltoidx[el].push_back(i);
    }
    bool sol = false;
    for (auto v : st)
    {
        if (st.find(x - v) != st.end())
        {
            if (x - v == v && eltoidx[v].size() == 1)
            {
                continue;
            }
            else if (x - v == v)
            {
                cout << eltoidx[v][0] << " " << eltoidx[v][1] << endl;
                sol = true;
                break;
            }
            else
            {
                cout << eltoidx[v][0] << " " << eltoidx[x - v][0] << endl;
                sol = true;
                break;
            }
        }
    }
    if (!sol)
    {
        cout << "IMPOSSIBLE" << endl;
    }
}