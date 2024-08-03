#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";

void solve()
{
    int n, q;
    cin >> n >> q;
    deque<int> dq;
    int maxEl = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        dq.push_back(el);
        maxEl = max(maxEl, el);
    }
    vector<pair<int, int>> sols;
    do
    {
        int front1 = dq.front();
        dq.pop_front();
        int front2 = dq.front();
        dq.pop_front();
        dq.push_front(max(front1, front2));
        dq.push_back(min(front1, front2));
        // note 0 indexed
        sols.push_back({front1, front2});

    } while (dq.front() != maxEl);

    vector<int> elsAfterMax;
    dq.pop_front(); // removing the max element
    // putting all elements after the max in their order in this vector
    while (dq.size() > 0)
    {
        elsAfterMax.emplace_back(dq.front());
        dq.pop_front();
    }

    while (q--)
    {
        lli x;
        cin >> x;
        if (x <= sols.size())
        {
            cout << sols[x - 1].first << " " << sols[x - 1].second << endl;
        }
        else
        {
            lli xnew = x - sols.size() - 1;
            int a = maxEl;
            int b = elsAfterMax[xnew % (n - 1)];
            cout << a << " " << b << endl;
        }
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