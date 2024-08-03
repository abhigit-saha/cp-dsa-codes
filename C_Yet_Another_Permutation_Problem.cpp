#include <bits/stdc++.h>

using namespace std;

using lli = long long;
#define endl "\n";
vector<int> primes;

bool isPrime[100100];
void precompute()
{
    int arr[100100];
    for (int i = i; i < 100100; i++)
    {
        arr[i] = i;
        isPrime[i] = true;
    }
    for (int i = 2; i < 100100; i++)
    { // starting from element 2;
        if (isPrime[i])
        {
            for (int j = 2 * i; j <= 100100; j += i)
            {
                isPrime[j] = false;
            }
        } // is prime
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> perm;
    bool added[n + 1];
    added[0] = false;
    for (int i = 1; i <= n; i++)
    {
        added[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {

        if (!added[i])
        {
            int var = i;
            while (var <= n)
            {

                if (!added[var])
                {

                    perm.emplace_back(var);
                    added[var] = true;
                }
                var += var;
            }
        }
    }

    for (auto num : perm)
    {
        cout << num << " ";
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
    // precompute();
    while (t--)
        solve();
    return 0;
}