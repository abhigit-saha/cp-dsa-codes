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
vector<int> g[1001000];
int par[1001000];
int dist[1001000];
int subtreesz[1001000];
void dfs(int node, int parent, int depth)
{
    subtreesz[node] = 1;
    dist[node] = depth;
    par[node] = parent;
    for (auto v : g[node])
    {
        if (v == parent)
            continue;
        dfs(v, node, depth + 1);
        subtreesz[node] += subtreesz[v];
    }
}
void dfs(int node, int parent, int depth, int dia, int &cntr)
{

    if (depth == dia / 2)
        cntr++;
    for (auto v : g[node])
    {
        if (v == parent)
            continue;
        dfs(v, node, depth + 1, dia, cntr);
    }
}
void solve()
{
    // Your code here
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    dfs(1, 0, 0);

    int furthest_node = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dist[i] > dist[furthest_node])
            furthest_node = i;
    }
    dfs(furthest_node, 0, 0);
    furthest_node = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dist[i] > dist[furthest_node])
            furthest_node = i;
    }
    int dia = dist[furthest_node];
    if (dia % 2 == 0)
    {
        int temp = furthest_node;
        for (int i = 0; i < dia / 2; i++)
        {
            temp = par[temp];
        }
        int center = temp;
        vector<int> children;
        for (auto v : g[center])
        {
            children.push_back(v);
        }
        vector<int> req_children;
        for (auto c : children)
        {
            int req = 0;
            dfs(c, center, 1, dia, req);
            req_children.push_back(req);
        }
        // todo: take pairwise product of these
        vector<int> req_pfx(req_children.size());
        req_pfx[0] = req_children[0];
        int ans = 0;
        for (int i = 1; i < req_children.size(); i++)
        {
            req_pfx[i] = req_children[i] + req_pfx[i - 1];
            ans += req_children[i] * (req_pfx[i] - req_children[i]);
        }
        cout << ans << endl;
    }
    else
    {
        int temp = furthest_node;
        for (int i = 0; i < dia / 2; i++)
        {
            temp = par[temp];
        }
        int c1 = temp;
        int c2 = par[temp];
        vector<int> req_children;
        int req = 0;
        dfs(c1, c2, 0, dia, req);
        req_children.push_back(req);

        req = 0;
        dfs(c2, c1, 0, dia, req);
        req_children.push_back(req);
        int ans = 1;
        for (auto v : req_children)
        {
            ans *= v;
        }
        cout << ans << endl;
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