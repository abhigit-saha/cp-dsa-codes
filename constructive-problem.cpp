#include <bits/stdc++.h>

using namespace std;

using lli = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st.insert(arr[i]);
    }
    int mex = *st.rbegin() + 1;

    for (int i = 0; i < n; i++)
    {
        if (*st.begin() != i)
        {
            mex = i;
            st.erase(st.begin());
            break;
        }
        else
        {
            st.erase(st.begin());
        }
    }
    cout << mex << endl;
    int newMexCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == mex + 1)
        {
            newMexCnt++;
        }
    }
    if (newMexCnt == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == mex + 1)
            {
            }
        }
    }
    int l = 0, r = 0;
    while (newMexCnt != 0)
    {
        if (arr[l] == mex + 1)
        {
            r++;
            if (arr[r] == mex + 1)
            {
            }
            // newMexCnt--;
            // if (arr[r] < arr[l] && newMexCnt != 0)
            // {
            //     cout << "No" << endl;
            //     return;
            // }
        }
        else
        {
            l++;
            r++;
        }
    }
    cout << "Yes" << endl;
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