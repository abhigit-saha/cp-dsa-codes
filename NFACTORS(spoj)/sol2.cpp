#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000100
int is_prime[MAXN];
int prime_factors[MAXN];

map<int, vector<int>> mp;

void precompute()
{
    for (int i = 2; i < MAXN; i++)
    {
        is_prime[i] = 1;
        prime_factors[i] = 0;
    }
    for (int i = 2; i < MAXN; i++)
    { // NloglogN
        if (is_prime[i])
        {
            prime_factors[i]++;
            for (int j = 2 * i; j < MAXN; j += i)
            {
                is_prime[j] = 0;
                prime_factors[j]++;
            }
        }
    }
    for (int i = 1; i < MAXN; i++)
    {
        mp[prime_factors[i]].push_back(i);
    }
}

int main()
{
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> a >> b >> n;
        int ans = upper_bound(mp[n].begin(), mp[n].end(), b) - lower_bound(mp[n].begin(), mp[n].end(), a);
        cout << ans << endl;
    }

    return 0;
}