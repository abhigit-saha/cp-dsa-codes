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
#define endl "\n";
void formula(string s, map<string, int> &count)
{
    string currEl;
    for (int i = 0; i < s.size(); i++)
    {
        // if capital letter then new el starts
        if (s[i] < 'a' && s[i] > '9')
        {
            currEl = s[i];
            if (i + 1 == s.size())
            {
                count[currEl] += 1;
            }
        }
        // if small letter then added to the current el name
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            currEl += s[i];
            if (i + 1 == (s.size()))
            {
                count[currEl] += 1;
            }
        }
        // if num then count of currentEl incremented
        else if (s[i] < 'A' && !(s[i] == '(' || s[i] == ')'))
        {
            count[currEl] += (s[i] - '0');
        }
        // if open bracket then above performed on the substr of the string
        // else if (s[i] == '(')
        // {
        //     map<string, int> bktCount;
        //     int k = i;
        //     while (s[i] != ')')
        //     {
        //         i++;
        //     }
        //     if (i + 1 != s.size())
        //     {
        //         i++;
        //     }
        //     formula(s.substr(k, i), bktCount);
        //     // adding the elements counts inside the bracket to the main count
        //     if (s[i] < 'a' && !(s[i] == '(' || s[i] == ')'))
        //     {
        //         for (auto [el, cnt] : bktCount)
        //         {
        //             count[el] += cnt * s[i];
        //         }
        //     }
        // }
    }
}
void solve()
{
    string s;
    cin >> s;
    map<string, int> count;
    formula(s, count);
    pr(count);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}