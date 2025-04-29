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

int pw(int a, int b, int mod)
{
    if (b == 0)
        return 1;
    int ans = pw(a, b / 2, mod);
    ans = (ans * ans) % mod;
    if (b % 2 == 1)
    {
        ans = (a * ans) % mod;
    }
    return ans;
}
int mod = 1e9 + 7;
vector<int> prime(10010001, 1);
void precompute() // the greatest prime number each number is divisble by.
{
    for (int i = 2; i <= 10010001; i++)
    {
        prime[i] = i;
    }
    for (int i = 2; i <= 10010001; i++)
    {
        if (prime[i] == i)
        {
            for (int j = i; j <= 10010001; j += i)
            {
                prime[j] = i;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    precompute();
    map<int, int> masterfact;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        map<int, int> fact;
        for (int j = 0; j < m; j++)
        {
            int el;
            cin >> el;
            while (el > 1)
            {
                fact[prime[el]]++;
                el /= prime[el];
            }
        }

        if (i == 0)
        {
            masterfact = fact;
        }
        else
        {
            for (auto v : masterfact)
            {
                masterfact[v.first] = min(masterfact[v.first], fact[v.first]);
            }
        }
    }

    int ans = 1;
    for (auto v : masterfact)
    {
        ans = (ans * pw(v.first, v.second, mod)) % mod;
    }
    cout << ans << endl;
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