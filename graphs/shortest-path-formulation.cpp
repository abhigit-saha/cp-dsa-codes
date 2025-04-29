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
#define F first
#define S second
void solve()
{
    // Your code here
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n + 1);
    vector<vector<pair<int, int>>> g(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(100100, 1e18)), vis(n + 1, vector<int>(100100));
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, p, d;
        g[a].push_back({b, p});
        g[b].push_back({a, p});
    }
    int st, end;
    cin >> st >> end;

    dist[st][k] = 0;
    vis[st][k] = 0;
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, {st, k}});
    while (!q.empty())
    {
        pair<int, pair<int, int>> x = q.top();
        q.pop();
        int curdist = -x.F;
        int node = x.S.F;
        int tank = x.S.S;
        if (vis[node][tank])
            continue;
        vis[node][tank] = 1;
        for (auto v : g[node])
        {
            int ngh = v.F;
            int ptl = v.S;

            // go to the neighboring node;
            if (tank >= ptl)
            {
                if (!vis[ngh][tank - ptl] && dist[ngh][tank - ptl] > dist[node][tank])
                {
                    dist[ngh][tank - ptl] = dist[node][tank];
                    q.push({-dist[ngh][tank - ptl], {ngh, tank - ptl}});
                }
            }
        }
        // increase the tank here itself;

        if (tank < k)
        {
            if (!vis[node][tank + 1] && dist[node][tank + 1] > dist[node][tank] + c[node])
            {
                dist[node][tank + 1] = dist[node][tank] + c[node];
                q.push({-dist[node][tank + 1], {node, tank + 1}});
            }
        }
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