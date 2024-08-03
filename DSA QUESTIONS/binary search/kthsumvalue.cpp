#include <bits/stdc++.h>

using namespace std;

using lli = long long;
//---- Debugger ---- //
#define debarr(a, n)            \
    cout << #a << " : ";        \
    for (int i = 0; i < n; i++) \
        cerr << a[i] << " ";    \
    cerr << endl;
#define debmat(mat, row, col)         \
    cout << #mat << " :\n";           \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cerr << mat[i][j] << " "; \
        cerr << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const unordered_set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
    os << "[ ";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
void dbs(string str, T t) { cerr << str << " : " << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
    int idx = str.find(',');
    cerr << str.substr(0, idx) << " : " << t << ",";
    dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b)
{
    cerr << "[";
    for (T i = a; i != b; ++i)
    {
        if (i != a)
            cerr << ", ";
        cerr << *i;
    }
    cerr << "]\n";
}
lli binpow(lli b, lli p, lli mod)
{
    lli ans = 1;
    b %= mod;
    for (; p; p >>= 1)
    {
        if (p & 1)
            ans = ans * b % mod;
        b = b * b % mod;
    }
    return ans;
}
//----------------- //
vector<lli> a;
vector<lli> b;
lli n, m, k;

lli check(lli mid)
{
    lli var = 0;
    for (lli i = 0; i < n; i++)
    {
        var += (upper_bound(b.begin(), b.end(), mid - a[i]) - b.begin());
        if (var >= k)
        {
            return 1;
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lli i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    if (n > m)
    {
        swap(a, b); // eg. a: 10(n), b: 7(m)-> a: 7(n), b: 10(m)
        swap(n, m); // such that a is always the smaller array.
    }

    lli lo = a[0] + b[0], hi = a[n - 1] + b[m - 1], ans = 0; // ans could be anything.

    while (lo <= hi)
    {
        lli mid = lo + (hi - lo) / 2;
        if (check(mid) == 1)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}