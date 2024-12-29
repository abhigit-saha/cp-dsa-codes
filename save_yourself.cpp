#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl '\n'

#define debarr(a, n)            \
    cout << #a << ':';          \
    for (int i = 0; i < n; i++) \
        cout << a[i] << ' ';    \
    cout << endl;

// Operator overloading for pairs
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    return os << '(' << p.first << ',' << p.second << ')';
}

// Operator overloading for vectors
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '[';
    for (const auto &it : v)
        os << it << ' ';
    return os << ']';
}

// Operator overloading for sets
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << '[';
    for (const auto &it : s)
        os << it << ' ';
    return os << ']';
}

// Operator overloading for unordered sets
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &us)
{
    os << '[';
    for (const auto &it : us)
        os << it << ' ';
    return os << ']';
}

// Operator overloading for maps
template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m)
{
    os << '[';
    for (const auto &it : m)
        os << it << ' ';
    return os << ']';
}

// Operator overloading for unordered maps
template <typename K, typename V>
ostream &operator<<(ostream &os, const unordered_map<K, V> &um)
{
    os << '[';
    for (const auto &it : um)
        os << it << ' ';
    return os << ']';
}

// Operator overloading for multisets
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &ms)
{
    os << '[';
    for (const auto &it : ms)
        os << it << ' ';
    return os << ']';
}

// Debugging function
template <typename T>
void dbs(const string &str, T t)
{
    cerr << str << ':' << t << endl;
}

template <typename T, typename... S>
void dbs(const string &str, T t, S... s)
{
    size_t idx = str.find(',');
    cerr << str.substr(0, idx) << ':' << t << ',';
    dbs(str.substr(idx + 1), s...);
}

template <typename T>
void prc(T a, T b)
{
    cerr << '[';
    for (T i = a; i != b; ++i)
    {
        if (i != a)
            cerr << ',';
        cerr << *i;
    }
    cerr << ']' << endl;
}

// Binary exponentiation
int binpow(int b, int p, int mod)
{
    int ans = 1;
    b %= mod;
    while (p)
    {
        if (p & 1)
            ans = ans * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return ans;
}
int mod = 1e9 + 7;
vector<vector<char>> plot;
int n, m;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};
vector<vector<int>> monsterDist, aDist, vis;
bool isValid(pair<int, int> node)
{
    if (node.first < 0 || node.first >= n || node.second < 0 || node.second >= m || plot[node.first][node.second] == '#')
        return false;
    return true;
}
void solve()
{
    // Your code here
    cin >> n >> m;
    plot.resize(n, vector<char>(m));
    monsterDist.resize(n, vector<int>(m, 1e9));
    aDist.resize(n, vector<int>(m, 1e9));
    vis.resize(n, vector<int>(m, 0));

    queue<pair<int, int>> monster, a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> plot[i][j];
            if (plot[i][j] == 'M')
            {
                monster.push({i, j});
                monsterDist[i][j] = 0;
            }
            if (plot[i][j] == 'A')
            {
                a.push({i, j});
                aDist[i][j] = 0;
            }
        }
    }

    while (!monster.empty())
    {
        pair<int, int> x = monster.front();

        monster.pop();
        if (vis[x.first][x.second])
            continue;
        vis[x.first][x.second] = 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = x.first + dx[i];
            int yy = x.second + dy[i];
            if (isValid({xx, yy}) && monsterDist[xx][yy] > monsterDist[x.first][x.second] + 1)
            {
                monsterDist[xx][yy] = monsterDist[x.first][x.second] + 1;
                monster.push({xx, yy});
            }
        }
    }
    vis.assign(n, vector<int>(m, 0));
    while (!a.empty())
    {
        pair<int, int> x = a.front();
        a.pop();
        if (vis[x.first][x.second])
            continue;
        vis[x.first][x.second] = 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = x.first + dx[i];
            int yy = x.second + dy[i];
            if (isValid({xx, yy}) && aDist[xx][yy] > aDist[x.first][x.second] + 1)
            {
                aDist[xx][yy] = aDist[x.first][x.second] + 1;
                a.push({xx, yy});
            }
        }
    }
    int dist = 1e9, possible = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (aDist[i][j] < monsterDist[i][j])
                {
                    possible = 1;
                    dist = min(dist, aDist[i][j]);
                }
            }
        }
    }
    if (possible)
    {
        cout << "YES" << endl;
        cout << dist << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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