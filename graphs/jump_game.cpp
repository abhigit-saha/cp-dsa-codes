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
vector<pair<int, int>> g[1001000];
int dist[1001000];
int vis[1001000];

void solve()
{
    // Your code here
    memset(vis, 0, sizeof(vis));

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nodes(n + 1);
    set<int> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i];
        d.insert(nodes[i]);
    }

    int distinct = d.size();

    for (int i = 1; i <= n; i++)
    {

        if (i != n)
        {
            g[i].push_back({i + 1, b});
        }
        if (i != 1)
        {
            g[i].push_back({i - 1, b});
        }
        g[i].push_back({(int)1e6 + nodes[i], 0});
        g[(int)1e6 + nodes[i]].push_back({i, a});
    }
    for (auto v : g)
    {
        for (auto [node, wt] : v)
        {
            dist[node] = 1e18;
        }
    }

    int sc;
    cin >> sc;
    dist[sc] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, sc});
    while (!q.empty())
    {
        pair<int, int> x = q.top();
        q.pop();
        int node = x.second;
        if (vis[node])
            continue;
        vis[node] = 1;
        for (auto [ngh, wt] : g[node])
        {
            if (dist[ngh] > dist[node] + wt)
            {
                dist[ngh] = dist[node] + wt;
                q.push({-dist[ngh], ngh});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
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