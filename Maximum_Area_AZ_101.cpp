#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
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
    lli h, w, n;

    cin >> h >> w >> n;
    multiset<lli> hseg, wseg, hcut, wcut;
    hseg.insert(h);
    wseg.insert(w);
    hcut.insert(0);
    wcut.insert(0);
    while (n--)
    {
        char move;
        int d;

        cin >> move >> d;
        // pr(hseg);
        // pr(wseg);
        if (move == 'H')
        {

            hcut.insert(d);
            auto it = hcut.find(d);
            it++;
            int upcut = h;
            if (it != hcut.end())
            {
                upcut = *it;
            }
            it--;
            it--;
            int lowcut = *it;
            hseg.insert(d - lowcut);
            hseg.insert(upcut - d);
            hseg.erase(hseg.find(upcut - lowcut));
            cout << (*hseg.rbegin()) * (*wseg.rbegin()) << endl;
        }
        if (move == 'V')
        {

            wcut.insert(d);
            auto it = wcut.find(d);
            it++;
            int rightcut = w;
            if (it != wcut.end())
            {
                rightcut = *it;
            }
            it--;
            it--;
            int leftcut = *it;
            wseg.insert(d - leftcut);
            wseg.insert(rightcut - d);

            wseg.erase(wseg.find(rightcut - leftcut));

            cout << (*hseg.rbegin()) * (*wseg.rbegin()) << endl;
        }
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