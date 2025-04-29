#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll fact[1001000];
#define endl "\n";
void precompute()
{
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < 1001000; i++)
    {
        fact[i] = (i * (fact[i - 1] % mod)) % mod;
    }
}
ll binpow(ll a, ll b, ll mod)
{
    ll ans = 1;
    if (b == 0)
        return 1;
    if (b % 2 == 1)
    {
        ans = (a * binpow(a, b - 1, mod) % mod) % mod;
    }
    else
    {
        ll term = (binpow(a, b / 2, mod) % mod);
        ans = (term * term) % mod;
    }
    // cout << ans << endl;
    if (ans < 0)
        return ans + mod;
    return ans;
}

ll ncr(ll n, ll r)
{
    assert(r <= n && r >= 0 && n >= 1);
    ll ans = fact[n] % mod;
    ans *= binpow(fact[n - r], mod - 2, mod) % mod;
    ans %= mod;
    ans *= binpow(fact[r], mod - 2, mod) % mod;
    ans %= mod;

    return ans;
}

int main()
{
    precompute();
    ll n, m, k;
    cin >> n >> m >> k;
    ll m3 = binpow(fact[n - 1], mod - 2, mod);
    ll ans = 0;
    for (ll i = 0; k - i * m >= 0; i++)
    {
        ll mult = ncr(n, i);
        ll m1 = fact[k - i * m + n - 1];
        ll m2 = binpow(fact[k - i * m], mod - 2, mod) % mod;
        if (i % 2 == 1)
        {
            ans -= (((mult * (m1)) % mod * m2) % mod) * m3 % mod;
        }
        else
        {
            ans += (((mult * (m1)) % mod * m2) % mod) * m3 % mod;
        }
        if (ans < 0)
            ans += mod;
        ans %= mod;
    }
    cout << ans << endl;
}
// ll main()
// {
//     precompute();
//     // for (int i = 1; i <= 100; i++)
//     // {
//     //     cout << fact[i] << " ";
//     // }
//     // cout << endl;
//     ll n, m, k;
//     cin >> n >> m >> k;
//     ll ans = 0;
//     for (int i = 0; k - i * m >= 0; i++)
//     {
//         int term = fact[k - i * m + n - 1];

//         // cout << term << endl;
//         term *= (binpow(fact[k - i * m], mod - 2, mod)) % mod;
//         term = (term + mod) % mod;
//         // cout << term << endl;
//         term *= (binpow(fact[n - 1], mod - 2, mod) % mod);
//         term = (term + mod) % mod;

//         int mult = fact[n];
//         mult *= (binpow(fact[n - i], mod - 2, mod) % mod);
//         mult %= mod;
//         mult *= (binpow(fact[i], mod - 2, mod) % mod);
//         mult %= mod;
//         ans += (mult * term);
//         ans %= mod;
//     }
//     cout << ans << endl;
// }