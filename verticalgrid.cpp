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

#define F first
#define S second
int mod = 1e9 + 7;
vector<string> grid;
int n;
void gravity(int col)
{
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (grid[i][col] != '0')
        {
            st.push(grid[i][col]);
        }
    }
    int dfc = 0;
    while (!st.empty())
    {
        grid[(n - 1) - dfc][col] = st.top();
        st.pop();
        dfc++;
    }
    for (int i = 0; i <= (n - 1) - dfc; i++)
    {
        grid[i][col] = '0';
    }
}
vector<vector<int>> vis;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= 10)
        return false;
    return true;
}
void dfs(pair<int, int> node, int &size, int del)
{
    vis[node.F][node.S] = 1 + del;

    char val = grid[node.F][node.S];
    if (del)
    {
        grid[node.F][node.S] = '0';
    }
    else
    {
        size++;
    }
    for (int i = 0; i < 4; i++)
    {
        int nr = node.F + dx[i];
        int nc = node.S + dy[i];

        if (valid(nr, nc) && !(vis[nr][nc] == 1 + del) && grid[nr][nc] == val)
        {
            dfs({nr, nc}, size, del);
        }
    }
}
void solve()
{
    // Your code here
    int k;
    cin >> n >> k;
    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     gravity(i);
    // }
    // cout << "------------------------------" << endl;
    // vector<int> sizes;
    bool complete = false;
    // vis.resize(n, vector<int>(10, 0));
    while (!complete)
    {
        vis.assign(n, vector<int>(10, 0));
        int maxsize = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {

                if (!vis[i][j] && grid[i][j] != '0')
                {
                    int size = 0;
                    dfs({i, j}, size, 0);
                    if (size >= k)
                    {
                        dfs({i, j}, size, 1);
                    }
                    maxsize = max(size, maxsize);
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            gravity(i);
        }
        if (maxsize < k)
            complete = true;
    }

    for (int i = 0; i < n; i++)
    {
        cout << grid[i] << endl;
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