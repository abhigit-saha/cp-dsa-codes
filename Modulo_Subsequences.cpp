#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int m;
vector<int> generate(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    vector<int> sums;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            {
                sum += (arr[i] % m);
                sum %= m;
            }
        }
        sums.push_back(sum);
    }
    sort(sums.begin(), sums.end());
    return sums;
}
signed main()
{
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n >> m;
        vector<int> arrs[2];
        for (int i = 0; i < n; i++)
        {

            int el;
            cin >> el;
            arrs[i & 1].push_back(el);
        }

        vector<int> sums1 = generate(arrs[0]);
        vector<int> sums2 = generate(arrs[1]);

        int ans = 0;
        for (auto el : sums1)
        {
            auto it = upper_bound(sums2.begin(), sums2.end(), m - 1 - el);
            it--;
            int el2 = *it;
            ans = max(ans, el2 + el);
        }
        cout << ans << endl;
    }
    return 0;
}