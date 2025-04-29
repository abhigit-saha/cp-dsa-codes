#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define F first
#define S second
vector<vector<char>> g;
vector<vector<int>> mdist, dist, vis;
int n, m;
vector<int> dr = {1, -1, 0, 0}, dc = {0, 0, 1, -1};
bool is_valid(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] == '#')
        return false;
    return true;
}
signed main()
{
    cin >> n >> m;
    g.resize(n, vector<char>(m));
    mdist.resize(n, vector<int>(m, 1e9));
    dist.resize(n, vector<int>(m, 1e9));
    vis.resize(n, vector<int>(m, 0));
    queue<pair<int, int>> mq, q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'M')
            {
                mq.push({i, j});
                mdist[i][j] = 0;
            }
            if (g[i][j] == 'A')
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!mq.empty())
    {
        pair<int, int> x = mq.front();
        int row = x.F, col = x.S;
        mq.pop();
        if (vis[row][col])
            continue;
        vis[row][col] = 1;
        for (int k = 0; k < 4; k++)
        {
            if (!is_valid(row + dr[k], col + dc[k]))
                continue;
            if (mdist[row + dr[k]][col + dc[k]] > mdist[row][col] + 1)
            {
                mdist[row + dr[k]][col + dc[k]] = mdist[row][col] + 1;
                mq.push({row + dr[k], col + dc[k]});
            }
        }
    }

    vis.assign(n, vector<int>(m, 0));

    while (!q.empty())
    {
        pair<int, int> x = q.front();
        int row = x.F, col = x.S;
        q.pop();
        if (vis[row][col])
            continue;
        vis[row][col] = 1;
        for (int k = 0; k < 4; k++)
        {
            if (!is_valid(row + dr[k], col + dc[k]))
                continue;
            if (dist[row + dr[k]][col + dc[k]] > dist[row][col] + 1)
            {
                dist[row + dr[k]][col + dc[k]] = dist[row][col] + 1;
                q.push({row + dr[k], col + dc[k]});
            }
        }
    }

    map<pair<int, int>, char> mp;
    mp[{-1, 0}] = 'U';
    mp[{1, 0}] = 'D';
    mp[{0, -1}] = 'L';
    mp[{0, 1}] = 'R';
    vector<char> path;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != 0 && i != n - 1 && j != 0 && j != m - 1)
                continue;
            if (dist[i][j] < mdist[i][j])
            {
                cout << "YES" << endl;
                cout << dist[i][j] << endl;

                int r = i, c = j;
                while (g[r][c] != 'A')
                {
                    int min_dist = 1e9;
                    int next_r = -1, next_c = -1;

                    for (int k = 0; k < 4; k++)
                    {
                        int new_r = r + dr[k];
                        int new_c = c + dc[k];

                        if (!is_valid(new_r, new_c))
                            continue;

                        if (dist[new_r][new_c] < min_dist)
                        {
                            min_dist = dist[new_r][new_c];
                            next_r = new_r;
                            next_c = new_c;
                        }
                    }

                    path.push_back(mp[{r - next_r, c - next_c}]);
                    r = next_r;
                    c = next_c;
                }

                reverse(path.begin(), path.end());
                for (char p : path)
                    cout << p;
                cout << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}
