#include <bits/stdc++.h>
#define endl "\n";
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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<lli> a, b;
    vector<lli> prog, test;
    lli ans = 0;
    for (int i = 0; i < n + m + 1; i++)
    {
        int el;
        cin >> el;
        a.emplace_back(el);
    }
    for (int i = 0; i < n + m + 1; i++)
    {
        int el;
        cin >> el;
        b.emplace_back(el);
        if (test.size() == m + 1)
        {
            for (int j = i; j < n + m + 1; j++)
            {
                prog.emplace_back(a[j]);
                ans += a[j];
            }
            break;
        }
        if (prog.size() == n + 1)
        {
            for (int j = i; j < n + m + 1; j++)
            {
                test.emplace_back(b[j]);
                ans += b[j];
            }
            break;
        }

        if (b[i] > a[i])
        {
            test.emplace_back(b[i]);
            ans += b[i];
            continue;
        }
        if (b[i] < a[i])
        {
            prog.emplace_back(a[i]);
            ans += a[i];
            continue;
        }
    }
    cout << ans << endl;
    pr(prog);
    pr(test);
    for (int i = 0; i < n + m + 1; i++)
    {
        lli temp = ans;
        if (prog.size() == n + 1 && i <= n + 1)
        {
            if (a[i] > b[i])
            {
                temp -= a[i];
                cout << temp << endl;
                continue;
            }
        }
        else
        {
            temp -= b[i];
            temp += prog[n + 1];
            cout << temp << endl;
            continue;
        }
        if (test.size() == m + 1 && i <= m + 1)
        {
            if (b[i] > a[i])
            {
                temp -= b[i];
                cout << temp << " ";
                continue;
            }
        }
        else
        {
            temp -= a[i];
            temp += test[m + 1];
            cout << temp << " ";
            continue;
        }
        cout << endl;
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