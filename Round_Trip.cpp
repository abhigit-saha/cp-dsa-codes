#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
vector<vector<int>> g(1001000);
int vis[1001000];
int parent[1001000];
vector<int> cycle;
bool found = false;
int st = -1, ending = -1;
void dfs(int node, int par)
{

    parent[node] = par;
    vis[node] = 2;
    for (auto v : g[node])
    {
        if (v == par)
            continue;
        if (vis[v] == 2 && !found)
        {
            found = true;
            st = node;
            ending = v;
        }
        else if (vis[v] == 1)
        {
            dfs(v, node);
        }
    }
    vis[node] = 3;
}

signed main()
{
    ios_base::sync_with_stdio(false); // Added for faster I/O
    cin.tie(NULL);                    // Added for faster I/O

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
        {
            dfs(i, 0);
        }
    }

    if (!found) // Changed condition to check for valid cycle
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {

        int temp = st;
        cycle.push_back(temp);
        while (temp != ending)
        {
            temp = parent[temp];
            cycle.push_back(temp);
        }
        cycle.push_back(st);
        cout << cycle.size() << endl;

        for (auto v : cycle)
        {
            cout << v << " ";
        }
        cout << endl;

        // do
        // {
        //     temp = parent[temp];
        //     cycle.push_back(temp);
        // } while (temp != st);

        // cout << cycle.size() << endl;
        // for (auto v : cycle)
        // {
        //     cout << v << " ";
        // }
        // cout << endl;
    }
}