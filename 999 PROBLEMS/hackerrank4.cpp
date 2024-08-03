#include <bits/stdc++.h>

using namespace std;

using lli = long long;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
void solve()
{
    int n;

    int q;
    vector<int> arr;
    vector<int> qarr;
    map<int, int> gcdmp;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        arr.emplace_back(el);
    }
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int el;
        cin >> el;
        qarr.emplace_back(el);
    }

    for (int k = 0; k < n; k++)
    {
        for (int l = k; l < n; l++)
        {
            if (l == k)
            {
                int g = arr[k];
                gcdmp[g]++;
            }
            else if (l == k + 1)
            {
                int g = gcd(arr[k], arr[l]);
                gcdmp[g]++;
            }
            else
            {
                int g = gcd(arr[k], arr[k + 1]);
                for (int m = k + 2; m <= l; m++)
                {
                    g = gcd(g, arr[m]); // Changed from arr[k] to arr[m]
                }
                gcdmp[g]++;
            }
        }
    }
    int ans = 0;

    for (int i = 0; i < q; i++)
    {
        ans += gcdmp[qarr[i]];
        cout << ans << " ";
    }

    cout << "\n";

    int uq = 0;
    for (auto it = gcdmp.begin(); it != gcdmp.end(); ++it)
    {
        uq++;
    }
    cout << uq;
    return;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    // while (t--)
    solve();
    return 0;
}