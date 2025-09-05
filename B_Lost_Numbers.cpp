#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define S second
#define F first

int find(pair<int, int> p, pair<int, int> q)
{
    if (p.F == q.S || p.F == q.F)
        return p.F;
    return p.S;
}
signed main()
{
    set<int> st;
    vector<int> vec = {4, 8, 15, 16, 23, 42};
    unordered_map<int, int> taken;
    map<int, pair<int, int>> mp;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            mp[vec[i] * vec[j]] = {vec[i], vec[j]};
        }
    }
    pair<int, int> prev;
    int cur = 1;
    vector<int> ans(7), pdts(5);
    for (int i = 1; i <= 4; i++)
    {
        cout << "?" << " " << cur << " " << cur + 1 << endl;
        cout.flush();
        cur++;

        int pdt;
        cin >> pdt;
        pdts[i] = pdt;
        if (i == 1)
        {
            prev = mp[pdt];
        }
        else
        {
            pair<int, int> curels = mp[pdt];
            int common = find(curels, prev);
            ans[cur - 1] = common;

            ans[cur] = pdt / common;
            ans[cur - 2] = pdts[i - 1] / common;
            prev = curels;
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        taken[ans[i]] = 1;
    }
    for (int i = 1; i <= 6; i++)
    {
        if (!taken[vec[i - 1]])
        {
            ans[6] = vec[i - 1];
            break;
        }
    }

    cout << "!" << " ";
    for (int i = 1; i <= 6; i++)
        cout << ans[i] << " ";
    cout << endl;
    cout.flush();
}