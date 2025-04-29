#include <bits/stdc++.h>
#define endl "\n";
#define int long long
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> sums(n), mxsub(n), maxpfxs(n), maxsfxs(n);
        vector<vector<int>> arrs(n);

        for (int i = 0; i < n; i++)
        {
            vector<int> pfx(n + 1, 0), sfx(n + 1, 0);
            int l;
            cin >> l;
            int sum = 0;
            pfx[0] = 0;
            int maxpfx = -1e9;
            for (int j = 0; j < l; j++)
            {
                int el;
                cin >> el;
                arrs[i].push_back(el);
                sum += el;
                pfx[j + 1] = el + pfx[j];
                maxpfx = max(maxpfx, pfx[j + 1]);
            }
            sfx[0] = sum;
            int maxsfx = sum;
            int ksum = 0, maxm = -1e9;
            for (int j = 0; j < l; j++)
            {
                maxm = max(maxm, arrs[i][j]);
                ksum += arrs[i][j];
                if (ksum < 0)
                    ksum = 0;
                maxm = max(ksum, maxm);
                sfx[j + 1] = sfx[j] - arrs[i][j];
                maxsfx = max(maxsfx, sfx[j + 1]);
            }
            sums[i] = sum;
            mxsub[i] = maxm;
            maxpfxs[i] = maxpfx;
            maxsfxs[i] = maxsfx;
        }
        vector<int> big(m);
        int rsum = sums[0], rmaxpfxs = maxpfxs[0], rmaxsfxs = maxsfxs[0], rmaxsub = mxsub[0];
        for (int i = 0; i < m; i++)
        {
            cin >> big[i];
            if (i != 0)
            {
                rmaxsub = max(mxsub[i], rmaxsfxs + maxpfxs[i], rmaxsub);
                rmaxpfxs = max(rmaxpfxs, rsum + maxpfxs[i]);
                rmaxsfxs = max(maxsfxs[i], sums[i] + rmaxsfxs);
                rsum = sums[i] + rsum;
            }
        }
        cout << rmaxsub << endl;
    }
    return 0;
}