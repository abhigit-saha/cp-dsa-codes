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
        map<int, vector<int>> mp;
        string q;
        for (int i = 1; i <= n; i++)
        {
            q += to_string(i);
            if (i < n)
                q += " ";
        }
        int maxsz = 0;
        for (int i = 1; i <= n; i++)
        {
            cout << "?" << " " << i << " " << q << endl;
            cout.flush();
            int sz;
            cin >> sz;
            maxsz = max(maxsz, sz);
            mp[sz].push_back(i);
        }
        int curnode = mp[maxsz][0];
        vector<int> ans;
        ans.push_back(curnode);
        int cursz = maxsz - 1;
        while (cursz)
        {
            for (auto el : mp[cursz])
            {
                cout << "?" << " " << curnode << " " << curnode << " " << el << endl;
                cout.flush();
                int sz;
                cin >> sz;
                if (sz == 1)
                    continue;
                curnode = el;
                ans.push_back(curnode);
                cursz--;
                break;
            }
        }
        cout << "! " << ans.size() << " ";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
        cout.flush();
    }
}