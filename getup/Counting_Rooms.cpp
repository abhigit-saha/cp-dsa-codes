#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

char grid[1002][1002];
vector<vector<int>> vis;

vector<int> dr = {0, 0, 1, -1}, dc = {1, -1, 0, 0};
vector<int> g[1001000];
int n, m;
bool is_valid(int r, int c)
{
    if (r > n || r < 1 || c > m || c < 1)
        return false;
    return true;
}
signed main()
{
    cin >> n >> m;
    vis.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int comp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int> x = q.front();
                    q.pop();
                    if (vis[x.first][x.second])
                        continue;
                    vis[x.first][x.second] = 1;
                    for (int k = 0; k < 4; k++)
                    {
                        if (!is_valid(x.first + dr[k], x.second + dc[k]))
                            continue;
                        if (grid[x.first + dr[k]][x.second + dc[k]] == '.')
                        {
                            q.push({x.first + dr[k], x.second + dc[k]});
                        }
                    }
                }
                comp++;
            }
        }
    }
    cout << comp << endl;
}