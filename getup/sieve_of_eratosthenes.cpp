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
vector<int> isPrime(1001000, 1);
void precompute()
{
    for (int i = 2; i * i <= 1e6; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}
void solve()
{
    // Your code here
    precompute();
    int l, r;

    cin >> l >> r;
    vector<int> arr(r - l + 1, 1);
    for (int i = 2; i <= sqrt(r); i++)
    {

        if (isPrime[i])
        {

            int first = ((l + i - 1) / i) * i;
            if (first == 0) 
                cout << "offender: " << l << " " << i << endl;
            for (int j = first; j <= r; j += i)
            {
                if (i != j)
                {
                    // cout << first << " ";
                    // cout << j - l << " ";
                    arr[j - l] = 0;
                }
            }
        }
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] && i + l >= 2)
        {
            // cout << i + l << " ";
            cnt++;
            ans.push_back(i + l);
        }
    }
    cout << cnt << endl;
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
    // for (int i = 2; i <= 100; i++)
    // {
    //     cout << isPrime[i] << " ";
    // }
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