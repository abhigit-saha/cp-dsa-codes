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
struct UnionFind
{
    int n, set_size, *parent, *rank;
    UnionFind() {};
    UnionFind(int a)
    {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 1; i <= n; i++)
            parent[i] = i, rank[i] = 1;
    }
    int find(int x)
    {
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return x;
    }
    void merge(int x, int y)
    {
        int xroot = find(x), yroot = find(y);
        if (xroot == yroot)
            return;
        if (rank[xroot] > rank[yroot])
        {
            parent[yroot] = x;
            rank[xroot] += rank[yroot];
        }
        else
        {
            parent[xroot] = y;
            rank[yroot] += rank[xroot];
        }
        set_size -= 1;
    }
    void reset()
    {
        set_size = n;
        for (int i = 1; i <= n; i++)
            parent[i] = i, rank[i] = 1;
    }
};
void solve()
{
    // Your code here
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> edgelist(m + 1);
    vector<int> exists(m + 1, 1);
    UnionFind uf(n);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        edgelist[i] = {a, b};
    }
    vector<int> commands;
    while (q--)
    {
        int com;
        cin >> com;
        if (com == 1)
        {
            int x;
            cin >> x;
            commands.push_back(x);
            exists[x] = 0;
        }
        else
        {
            commands.push_back(-1);
        }
    }
    reverse(commands.begin(), commands.end());
    vector<int> answers;
    for (int i = 1; i <= m; i++)
    {
        if (exists[i])
        {
            uf.merge(edgelist[i].first, edgelist[i].second);
        }
    }
    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i] == -1)
        {
            answers.push_back(uf.set_size);
        }
        else
        {
            uf.merge(edgelist[commands[i]].first, edgelist[commands[i]].second);
        }
    }

    reverse(answers.begin(), answers.end());
    for (auto ans : answers)
    {
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