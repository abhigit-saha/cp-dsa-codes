#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define int long long

// Ordered Set (Policy Based Data Structure)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// Custom printing for containers
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i];
        if (i != (int)v.size() - 1)
            os << ", ";
    }
    return os << "]";
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "{";
    auto it = s.begin();
    for (int i = 0; i < (int)s.size(); i++)
    {
        os << *it;
        if (i != (int)s.size() - 1)
            os << ", ";
        it++;
    }
    return os << "}";
}

template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &s)
{
    os << "{";
    auto it = s.begin();
    for (int i = 0; i < (int)s.size(); i++)
    {
        os << *it;
        if (i != (int)s.size() - 1)
            os << ", ";
        it++;
    }
    return os << "}";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m)
{
    os << "{";
    auto it = m.begin();
    for (int i = 0; i < (int)m.size(); i++)
    {
        os << it->first << ": " << it->second;
        if (i != (int)m.size() - 1)
            os << ", ";
        it++;
    }
    return os << "}";
}

template <typename T>
ostream &operator<<(ostream &os, const deque<T> &dq)
{
    os << "[";
    for (int i = 0; i < (int)dq.size(); i++)
    {
        os << dq[i];
        if (i != (int)dq.size() - 1)
            os << ", ";
    }
    return os << "]";
}

template <typename T>
ostream &operator<<(ostream &os, const queue<T> &q)
{
    queue<T> temp = q;
    os << "[";
    bool first = true;
    while (!temp.empty())
    {
        if (!first)
            os << ", ";
        os << temp.front();
        temp.pop();
        first = false;
    }
    return os << "]";
}

template <typename T>
ostream &operator<<(ostream &os, const stack<T> &st)
{
    stack<T> temp = st;
    vector<T> v;
    while (!temp.empty())
    {
        v.push_back(temp.top());
        temp.pop();
    }
    reverse(v.begin(), v.end());
    return os << v;
}

template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T> &pq)
{
    priority_queue<T> temp = pq;
    os << "[";
    bool first = true;
    while (!temp.empty())
    {
        if (!first)
            os << ", ";
        os << temp.top();
        temp.pop();
        first = false;
    }
    return os << "]";
}

// For ordered_set
template <typename T>
ostream &operator<<(ostream &os, const ordered_set &s)
{
    os << "{";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (it != s.begin())
            os << ", ";
        os << *it;
    }
    return os << "}";
}

// Debug macro
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#else
#define debug(x)
#define debug2(x, y)
#endif

// Utility functions
template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template <typename T>
T power(T a, T b, T mod = 1e18)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

template <typename T>
T modInverse(T a, T mod)
{
    return power(a, mod - 2, mod);
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

vector<int> sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

vector<int> getFactors(int n)
{
    vector<int> factors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i != n / i)
                factors.push_back(n / i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

// Binary search templates
template <typename T>
int lower_bound_index(vector<T> &v, T val)
{
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}

template <typename T>
int upper_bound_index(vector<T> &v, T val)
{
    return upper_bound(v.begin(), v.end(), val) - v.begin();
}

// Coordinate compression
template <typename T>
void compress(vector<T> &v)
{
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e18;
const long double PI = acos(-1);

// Fast I/O
void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main()
{
    fast_io();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            st.insert(arr[i]);
        }
        sort(arr.begin(), arr.end());
        int lg = arr[n - 1];
        int pdt = 1, g = lg - arr[0];
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        for (int i = 0; i < n - 1; i++)
        {
            g = __gcd(g, lg - arr[i]);
        }
        int ex;
        for (int i = 1; i <= n+1; i++)
        {

            if (st.find(lg - g * i) == st.end())
            {
                ex = lg - g * i;
                break;
            }
        }

        arr.push_back(ex); 
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {

            ans += (lg - arr[i]) / g;
        }
        cout << ans << endl;
    }

    return 0;
}