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
void solve()
{
    // Your code here
    int d1, d2, x, y, k;
    cin >> d1 >> d2 >> x >> y >> k;
    int k1, k2;
    if (k % 2 == 0)
    {
        k1 = k / 2;
        k2 = k / 2;
    }
    else
    {
        k1 = k / 2 + 1;
        k2 = k / 2 + 1;
    }

    int ans1, ans2, ansbuf1, ansbuf2;
    if (d1 - x < x)
    {
        if (k1 % 2 == 1)
        {
            ans1 = ((k1 + 1) / 2) * d1 - x;
        }
        else
        {
            ans1 = ((k1 - 2) / 2) * d1 + x;
        }
        // int c = x;
        // d = 2 * c;
        // x = d - c;
    }
    else
    {
        if (k1 % 2 == 1)
        {
            ans1 = k1 / 2 * d1 + x;
        }
        else
        {
            ans1 = k1 / 2 * d1 - x;
        }
    }
    if (d2 - y < y)
    {
        if (k2 % 2 == 1)
        {
            ans2 = ((k2 + 1) / 2) * d2 - y;
        }
        else
        {
            ans2 = ((k2 - 2) / 2) * d2 + y;
        }
        // int c = y;
        // d = 2 * c;
        // y = d - c;
    }
    else
    {
        if (k2 % 2 == 1)
        {
            ans2 = k2 / 2 * d2 + y;
        }
        else
        {
            ans2 = k2 / 2 * d2 - y;
        }
    }
    cout << ans1 << " " << ans2 << endl;

    if (k % 2 == 0)
    {
        cout << max(ans1, ans2) << endl;
    }
    else
    {
        cout << min(ans1, ans2) << endl;
    }
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