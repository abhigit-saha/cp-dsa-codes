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
vector<int> dr = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};
vector<vector<char>> plot;
int n;
vector<vector<vector<long long>>> dp;

const long long INF = 1e18;

int rec(int row, int col, int dir)
{
    if (row >= n || col >= n || row < 0 || col < 0)
        return INF;

    if (plot[row][col] == '#')
        return INF;

    if (plot[row][col] == 'E')
        return 0;

    if (dp[row][col][dir] != -1)
        return dp[row][col][dir];

    long long ans = INF;

    int nr = row + dr[dir];
    int nc = col + dc[dir];
    long long forward = rec(nr, nc, dir);
    if (forward < INF)
        ans = forward + 1;

    int rightDir = (dir + 1) % 4;
    long long rightTurn = rec(row, col, rightDir);
    if (rightTurn < INF)
        ans = min(ans, rightTurn + 1000);

    int leftDir = (dir + 3) % 4;
    long long leftTurn = rec(row, col, leftDir);
    if (leftTurn < INF)
        ans = min(ans, leftTurn + 1000);

    return dp[row][col][dir] = ans;
}

void solve()
{
    cin >> n;
    plot.resize(n, vector<char>(n));
    dp.assign(n, vector<vector<long long>>(n, vector<long long>(4, -1)));

    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> plot[i][j];
            if (plot[i][j] == 'S')
                start = {i, j};
        }
    }

    long long ans = rec(start.first, start.second, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j][0] << " ";
        }
        cout << endl;
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