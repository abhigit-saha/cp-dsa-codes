#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

vector<int> g[1001000];
int vis[1001000];
bool possible = true;
void dfs(int node, int par, int col)
{
    if (vis[node] != -1)
    {
        if (col != vis[node])
            possible = false;
        return;
    }
    vis[node] = col;
    for (auto v : g[node])
    {
        if (v != par)
        {
            dfs(v, node, 3 - col);
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(vis, -1, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            dfs(i, 0, 1);
        }
    }
    if (!possible)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << vis[i] << " ";
        }
        cout << endl;
    }
}