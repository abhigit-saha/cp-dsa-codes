#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int mod = 1e9 + 7;

int binpow(int b, int p, int mod)
{
    int ans = 1;
    b %= mod;
    while (p)
    {
        if (p & 1)
            ans = (ans * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;
    int last = 1;

    for (int i = 1; i <= n; i = last + 1)
    {
        int floor_div = n / i; // Current floor(n/i) value
        last = n / floor_div;  // Last number with same floor(n/i)

        int count = (last - i + 1) % mod;
        if (count < 0)
            count += mod;

        int power = binpow(floor_div, m, mod);

        ans = (ans + (power * count) % mod) % mod;
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}