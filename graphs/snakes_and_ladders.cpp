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
void initialize()
{
}

void solve()
{
    // Your code here
    vector<vector<pair<int, int>>> g(101);
    for (int i = 1; i <= 99; i++)
    {
        for (int k = 1; k <= 6; k++)
        {
            if (i + k <= 100)
                g[i].push_back({i + k, 1});
        }
    }

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        g[a] = {{b, 0}};
    }
    int m;
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a] = {{b, 0}};
    }
    vector<int> dist(101, 1e18);
    vector<int> vis(101);
    dist[1] = 0;
    deque<int> dq;
    dq.push_front(1);
    while (!dq.empty())
    {
        int x = dq.front();
        dq.pop_front();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto [node, wt] : g[x])
        {
            if (dist[node] > dist[x] + wt)
            {
                dist[node] = dist[x] + wt;
            }
            if (!wt)
            {
                dq.push_front(node);
            }
            else
            {
                dq.push_back(node);
            }
        }
    }
    cout << (dist[100] == 1e18 ? -1 : dist[100]) << endl;
    g.clear();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}