#include <bits/stdc++.h>

using namespace std;
#define endl "\n";
#define MAXN 1000100
int isPrime[MAXN];
int primeCount[MAXN];
map<int, vector<int>> invMap;
void precompute()
{
    for (int i = 2; i < MAXN; i++)
    {
        isPrime[i] = 1;
        primeCount[i] = 0;
    }
    for (int i = 2; i < MAXN; i++)
    {
        if (isPrime[i])
        {
            primeCount[i]++;
            for (int j = 2 * i; j < MAXN; j += i)
            {
                isPrime[j] = 0;
                primeCount[j]++;
            }
        }
    }

    for (int i = 1; i < MAXN; i++)
    {
        invMap[primeCount[i]].push_back(i);
    }
}
using lli = long long;

void solve()
{

    int a, b, n;
    cin >> a >> b >> n;
    cout << upper_bound(invMap[n].begin(), invMap[n].end(), b) - lower_bound(invMap[n].begin(), invMap[n].end(), a) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    precompute();
    while (t--)
        solve();
    return 0;
}