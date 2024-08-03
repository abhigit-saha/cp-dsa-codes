#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

using lli = long long;

lli gcd(lli a, lli b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
void solve()
{
    int n;
    cin >> n;
    vector<lli> arr;

    for (int i = 0; i < n; i++)
    {
        lli el;
        cin >> el;
        if (el == 1)
        {
            cout << "Yes" << endl;
            return;
        }
        arr.emplace_back(el);
    }
    lli gcd1 = arr[0];
    lli gcd2 = 0;
    bool firsttime = false;
    for (int i = 1; i < n; i++)
    {
        if (gcd(gcd1, arr[i]) == 1 && !firsttime)
        {
            gcd2 = arr[i];
        }
        else if (gcd(gcd1, arr[i]) == 1 && firsttime)
        {
            gcd2 = gcd(gcd2, arr[i]);
        }
        else
        {
            gcd1 = gcd(gcd1, arr[i]);
        }
    }
    if (gcd2 == 1)
    {
        cout << "No" << endl;
        return;
    }

    int count = 0;
    set<lli> st;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == gcd1)
        {
            if (gcd2 == 0)
            {
                cout << "Yes" << endl;
                return;
            }
            st.insert(gcd1);
        }
        if (arr[i] == gcd2)
        {
            st.insert(gcd2);
        }
    }
    if (st.size() == 2)
    {
        cout << "Yes" << endl;
        return;
    }
    else
    {
        cout << "No" << endl;
        return;
    }

    return;
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