#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl '\n'
int mod = 1e9 + 7;
vector<int> vis, dis;
vector<vector<int>> g;

void bfs(int sc)
{

    queue<int> q;
    dis[sc] = 0;
    q.push(sc);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto v : g[x])
        {
            if (dis[v] > dis[x] + 1)
            {
                dis[v] = dis[x] + 1;
                q.push(v);
            }
        }
    }
}
void solve()
{
    // Your code here
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int n, m;
    cin >> n >> m;
    int ctr = 1;
    vector<vector<int>> plot(n + 2, vector<int>(m + 2));
    int st = 0, fin = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char el;
            cin >> el;

            if (el != '#')
            {
                plot[i][j] = ctr;
                if (el == 'S')
                {
                    st = ctr;
                }
                else if (el == 'F')
                {
                    fin = ctr;
                }
                ctr++;
            }
            else
            {
                plot[i][j] = -1;
            }
        }
    }
    g.resize(ctr);
    vis.assign(ctr, 0);
    dis.assign(ctr, 1e9);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (plot[i + dx[k]][j + dy[k]] < 1 || plot[i][j] < 1)
                    continue;
                g[plot[i][j]].emplace_back(plot[i + dx[k]][j + dy[k]]);
            }
        }
    }
    bfs(st);
    cout << dis[fin] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t; while (t--)
    solve();
    return 0;
}