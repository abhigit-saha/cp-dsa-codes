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
struct node
{
    int sum, lazy_a, lazy_d;
    node()
    {
        sum = 0;
        lazy_a = 0;
        lazy_d = 0;
    }
};
node merge(node a, node b)
{
    node c;
    c.sum = a.sum + b.sum;
    return c;
}
int arr[1001000];
node t[4004000];
void push(int id, int l, int r)
{
    int a = t[id].lazy_a, d = t[id].lazy_d;
    t[id].sum += (2 * a + (r - l) * d) * (r - l + 1) / 2;
    int mid = (r + l) / 2;
    if (l != r)
    {
        t[2 * id].lazy_a += a;
        t[2 * id].lazy_d += d;
        t[2 * id + 1].lazy_a += a + (mid - l + 1) * d;
        t[2 * id + 1].lazy_d += d;
        // t[2 * id].lazy = t[id].lazy / 2;
        // t[2 * id + 1].lazy = t[id].lazy / 2;
    }
    t[id].lazy_a = 0;
    t[id].lazy_d = 0;
}
void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id].sum = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int lq, int rq)
{
    if (t[id].lazy_a)
        push(id, l, r);
    if (lq > r || rq < l)
        return;
    if (lq <= l && rq >= r)
    {
        t[id].lazy_a = (l - lq + 1);
        t[id].lazy_d += 1;
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, lq, rq);
    update(2 * id + 1, mid + 1, r, lq, rq);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int id, int l, int r, int lq, int rq)
{
    if (t[id].lazy_a)
        push(id, l, r);
    if (lq > r || rq < l)
        return node();
    if (lq <= l && rq >= r)
    {
        return t[id];
    }
    int mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}
void solve()
{
    // Your code here
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            update(1, 0, n - 1, a, b);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            node c = query(1, 0, n - 1, a, b);
            cout << c.sum << endl;
        }
    }
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