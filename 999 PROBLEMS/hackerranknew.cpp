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
    cin >> n;
    vector<int> arr;
    vector<int> qarr;
    map<int, int> gcdmp;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        arr.emplace_back(el);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int el;
        cin >> el;
        qarr.emplace_back(el);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (j == i)
            {
                int g = arr[i];
                gcdmp[g]++;
            }
            else if (j == i + 1)
            {
                int g = gcd(arr[i], arr[j]);
                gcdmp[g]++;
            }
            else
            {
                int g = gcd(arr[i], arr[j]);
                for (int k = i + 2; k <= j; k++)
                {
                    g = gcd(g, arr[k]);
                }
                gcdmp[g]++;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {

        cout << gcdmp[qarr[i]] << " ";
    }
    cout << "\n";
    int queryCount = 0;
    for (auto i : gcdmp)
    {
        queryCount++;
    }
    cout << queryCount << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}