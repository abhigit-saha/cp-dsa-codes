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
vector<vector<int>> g;
vector<int> vis;
void dfs(int node, int par)
{
    vis[node] = 1;
    for (auto v : g[node])
    {
        if (v == par)
            continue;
        if (!vis[v])
        {
            dfs(v, node);
        }
    }
}
void solve()
{
    // Your code here
    int n, m;
    cin >> n >> m;
    int plot[n + 2][m + 2];
    int ctr = 1;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
            {
                plot[i][j] = 0;
                continue;
            }

            char el;
            cin >> el;
            if (el == '.')
            {
                plot[i][j] = ctr;
                ctr++;
            }
            else
            {
                plot[i][j] = -1;
            }
        }
    }

    g.resize(ctr + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (plot[i][j] == -1)
                continue;
            for (int k = -1; k <= 1; k++)
            {

                for (int l = -1; l <= 1; l++)
                {
                    if (plot[i + k][j + l] == 0 || plot[i + k][j + l] == -1 || (l == 0 && k == 0))
                        continue;

                    if (l * k == 0)
                        g[plot[i][j]].emplace_back(plot[i + k][j + l]);
                }
            }
        }
    }
    vis.assign(ctr, 0);
    int rooms = 0;
    for (int i = 1; i < ctr; i++)
    {
        if (!vis[i])
        {
            dfs(i, 0);
            rooms++;
        }
    }
    cout << rooms << endl;
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