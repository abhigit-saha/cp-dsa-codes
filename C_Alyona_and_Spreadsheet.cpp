#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        map<int, int> lgr;
        vector<vector<int>> table(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> table[i][j];
            }
        }
        for (int j = 1; j <= m; j++)
        {
            stack<int> st;
            for (int i = 1; i <= n; i++)
            {
                if (!st.empty() && table[st.top()][j] > table[i][j])
                {
                    while (!st.empty())
                    {
                        lgr[st.top()] = max(lgr[st.top()], i - 1);
                        st.pop();
                    }
                }

                st.push(i);
            }
            while (!st.empty())
            {
                lgr[st.top()] = n;
                st.pop();
            }
        }
        int k;
        cin >> k;
        while (k--)
        {
            int l, r;
            cin >> l >> r;
            if (lgr[l] >= r)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}