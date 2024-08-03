#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

// Function to perform modular exponentiation
long long mod_pow(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        long long term1 = mod_pow(9 / k + 1, r, MOD);
        long long term2 = mod_pow(9 / k + 1, l, MOD);
        long long result = (term1 - term2 + MOD) % MOD;

        cout << result << endl;
    }
    return 0;
}
