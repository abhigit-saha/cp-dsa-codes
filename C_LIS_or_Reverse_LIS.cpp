#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        set<int> st;
        map<int, int> freq;
        int cntmlt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        for (auto [el, fr] : freq)
        {
            if (fr >= 2)
                cntmlt++;
        }
        for (int i = 0; i < n; i++)
        {
            if (freq[arr[i]] == 1)
                st.insert(arr[i]);
        }

        int ans = cntmlt + (st.size() + 1) / 2;
        cout << ans << endl;
    }
    return 0;
}