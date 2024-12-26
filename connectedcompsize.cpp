
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

vector<vector<int>> dis;
vector<int> dx = {1, -1, 2, 2, 1, -1, -2, -2};
vector<int> dy = {2, 2, 1, -1, -2, -2, 1, -1};
bool is_valid(int x, int y, int n)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}
// void bfs(pair<int, int> st, int n, pair<int, int> end)
// {
//     queue<pair<int, int>> q;
//     q.push(st);
//     dis[st.F][st.S] = 0;

//     while (!q.empty())
//     {
//         pair<int, int> x = q.front();
//         q.pop();
//         vector<pair<int, int>> nbors = neighbors(x, n);
//         for (auto v : nbors)
//         {
//             if (v.F == end.F && v.S == end.S)
//             {
//                 dis[v.F][v.S] = dis[x.F][x.S] + 1;
//                 return;
//             }

//             if (dis[v.F][v.S] > dis[x.F][x.S] + 1)
//             {
//                 dis[v.F][v.S] = dis[x.F][x.S] + 1;
//                 q.push(v);
//             }
//         }
//     }
// }

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    dis.assign(N, vector<int>(N, 1e9));
    pair<int, int> st = {Sx - 1, Sy - 1}, end = {Fx - 1, Fy - 1};
    if (Sx == Fx && Fx == Fy)
        return 0;
    queue<pair<int, int>> q;
    q.push(st);
    dis[st.F][st.S] = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int x = cur.F + dx[i];
            int y = cur.S + dy[i];
            if (is_valid(x, y, N) && dis[x][y] > dis[cur.F][cur.S] + 1)
            {
                dis[x][y] = dis[cur.F][cur.S] + 1;
                q.push({x, y});
            }
        }
    }

    return dis[Fx - 1][Fy - 1] != 1e9 ? dis[Fx - 1][Fy - 1] : -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int N, Sx, Sy, Fx, Fy;
        cin >> N >> Sx >> Sy >> Fx >> Fy;
        cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
    }
}
