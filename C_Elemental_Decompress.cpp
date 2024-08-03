#include <bits/stdc++.h>

using namespace std;

using lli = long long;
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
#define endl "\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> absentEls;
    map<int, vector<int>> dblEls;
    bool valid = false;
    vector<int> p(n), q(n);

    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        // initially p and q are same as the given array.
        p[i] = el;
        q[i] = el;

        dblEls[el].emplace_back(i);

        if (el == n)
        {
            valid = true;
        }
    }
    if (!valid)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {

        if (dblEls.find(i) == dblEls.end())
        {
            absentEls.emplace_back(i);
        }
    }
    if (!absentEls.empty())
    {
        sort(absentEls.begin(), absentEls.end());
    }

    int i = 0;
    if (!absentEls.empty())
    {
        for (auto el : dblEls)
        {
            if (el.second.size() > 2)
            {
                cout << "NO" << endl;
                return;
            }
            if (el.first <= absentEls[i] && el.second.size() == 2)
            {
                cout << "NO" << endl;
                return;
            }
            // basically p and q are the same as the original array
            // except at indices of those elements where double elements are there
            // in those elements, in place of one of the double elements, corrosponding
            // absent element is placed. and the positions are swapped.
            if (el.second.size() == 2)
            {
                p[el.second[0]] = absentEls[i];
                p[el.second[1]] = el.first;
                q[el.second[0]] = el.first;
                q[el.second[1]] = absentEls[i];
                i++;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;
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