#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
vector<int> generate(const vector<int> &a)
{
    int n = a.size();
    vector<int> sums;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            {
                sum += a[i];
            }
        }

        sums.push_back(sum);
    }
    sort(sums.begin(), sums.end());
    return sums;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> split[2];
        for (int i = 0; i < n; i++)
        {
            split[i & 1].push_back(a[i]);
        }
        vector<int> sums1 = generate(split[0]);
        vector<int> sums2 = generate(split[1]);

        int ans = 0;
        for (auto el : sums1)
        {

            ans += upper_bound(sums2.begin(), sums2.end(), x - el) - sums2.begin();
        }

        cout << ans << endl;
    }
    return 0;
}