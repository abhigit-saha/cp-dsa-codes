#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int main()
{
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<ll, ll>>> g(n + 1);
    vector<ll> dists(n + 1, 1e16), distt(n + 1, 1e16);

    vector<pair<ll, pair<ll, ll>>> edgeList;
    vector<int> vis(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        edgeList.push_back({a, {b, c}});
    }
    dists[s] = 0;
    priority_queue<pair<ll, ll>> pq1;
    pq1.push({0, s});
    while (!pq1.empty())
    {
        auto x = pq1.top();
        pq1.pop();
        ll node = x.S;
        ll dist = -x.F;
        if (vis[node])
            continue;
        vis[node] = 1;
        for (auto v : g[node])
        {
            ll neigh = v.F;
            ll cost = v.S;

            if (dists[neigh] > dist + cost)
            {
                dists[neigh] = dist + cost;
                pq1.push({-dists[neigh], neigh});
            }
        }
    }
    vis.clear();
    vis.assign(n + 1, 0);
    distt[t] = 0;
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, t});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        ll node = x.S;
        ll dist = -x.F;
        if (vis[node])
            continue;
        vis[node] = 1;
        for (auto v : g[node])
        {
            ll neigh = v.F;
            ll cost = v.S;
            if (distt[neigh] > dist + cost)
            {
                distt[neigh] = dist + cost;
                pq.push({-distt[neigh], neigh});
            }
        }
    }

    for (auto e : edgeList)
    {
        ll x = e.F, y = e.S.F, cost = e.S.S;
        ll distance = min(distt[x] + dists[y] + cost, dists[x] + distt[y] + cost);
        if (distance >= 1e16)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << distance << " ";
        }
    }
    cout << endl;
}