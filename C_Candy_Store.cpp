#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> aibi(n), bi(n);
        int g, lb;
        int maxb = 0;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {

            int a, b;
            cin >> a >> b;

            aibi[i] = a * b;
            bi[i] = b;
            if (i == 0)
            {
                g = aibi[i];
                lb = bi[i];
            }

            if (i != 0)
            {
                g = __gcd(aibi[i], g);
                lb = bi[i] * lb / __gcd(lb, bi[i]);
                if (g % lb == 0)
                {
                    continue;
                }
                else
                {
                    ans++;
                    g = aibi[i];
                    lb = bi[i];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}