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
vector<vector<char>> plot;
vector<vector<int>> vis;
int n;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
bool valid(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > n)
        return false;
    return true;
}
void solve()
{
    // Your code here
    cin >> n;
    plot.resize(n + 2, vector<char>(n + 2, '.'));
    vis.assign(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> plot[i][j];
        }
    }
    vector<pair<int, int>> req; //{area, per}
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vis[i][j] && plot[i][j] == '#')
            {
                // cout << "HEY this is somthing: " << i << " " << j << endl;
                int area = 0, per = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (!q.empty())
                {
                    pair<int, int> x = q.front();
                    if (plot[x.F][x.S] == '#')
                    {
                        area++;
                    }
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        if (plot[x.F + dx[k]][x.S + dy[k]] == '.')
                            per++;
                        if (valid(x.F + dx[k], x.S + dy[k]) && !vis[x.F + dx[k]][x.S + dy[k]])
                        {
                            if (plot[x.F + dx[k]][x.S + dy[k]] == '#')
                            {
                                q.push({x.F + dx[k], x.S + dy[k]});
                                vis[x.F + dx[k]][x.S + dy[k]] = 1;
                            }
                        }
                    }
                }
                req.push_back({area, per});
            }
        }
    }
    sort(req.begin(), req.end(), [](pair<int, int> x1, pair<int, int> x2)
         {
             if (x1.F > x2.F)
                 return true;
             else if (x1.F == x2.F)
             {
                 return x1.S < x2.S;
             }
             return false; });

    cout << req[0].F << " " << req[0].S << endl;
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