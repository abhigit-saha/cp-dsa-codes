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

double dp[100100][2];
double n, g, v;

double rec(int rem, int turn)
{
    if (rem <= 0)
        return 0;
    if (dp[rem][turn] != -1.0)
    {
        return dp[rem][turn];
    }

    double ans = 0;
    if (turn == 1)
    {
        double gsum = 0;
        double vsum = 0;
        for (int i = 1; i <= v; i++)
        {
            gsum += rec(rem - i, 1);
        }
        for (int i = 1; i <= g; i++)
        {
            vsum += rec(rem - i, 0);
        }
        ans =
            1 +
            (1 / ((g + 1) * (v + 1))) * gsum +
            (1 / (g + 1)) * vsum;
    }
    else
    {

        double gsum = 0;
        double vsum = 0;
        for (int i = 1; i <= v; i++)
        {
            gsum += rec(rem - i, 1);
        }
        for (int i = 1; i <= g; i++)
        {
            vsum += rec(rem - i, 0);
        }
        ans =
            1 / (v + 1) +
            (1 / ((g + 1) * (v + 1))) * vsum +
            (1 / (v + 1)) * gsum;
    }
    ans = (((g + 1) * (v + 1)) / (g * v + v + g)) * ans;

    return dp[rem][turn] = ans;
}

void solve()
{
    cin >> n >> g >> v;
    for (int i = 0; i <= n; i++)
        dp[i][0] = dp[i][1] = -1.0;

    double ans = rec(n, 1);
    cout << fixed << setprecision(6) << ans << endl;
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