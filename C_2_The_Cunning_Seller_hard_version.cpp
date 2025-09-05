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
        int n, k;
        cin >> n >> k;
        int temp = n;

        vector<int> repr;
        while (temp)
        {
            repr.push_back(temp % 3);
            temp /= 3;
        }
        int sum = 0;
        int i = repr.size() - 1;
        int deals = 0;
        for (int i = 0; i < repr.size(); i++)
        {
            deals += repr[i];
        }

        i = repr.size() - 1;

        if (deals > k)
        {
            cout << -1 << endl;
        }
        else
        {
            k-=deals; 
            
            for (int i = repr.size() - 1; i >= 1; i--)
            {
                if (repr[i] <= k/2)
                {
                    repr[i - 1] += 3 * repr[i];
                    k -= 2*repr[i];
                    repr[i] = 0;
                }
                else
                {
                    repr[i - 1] += 3 * (k/2);
                    repr[i] -= (k/2);
                    break;
                }
            }

            int cost = 0;
            for (int i = 0; i < repr.size(); i++)
            {
                cost += repr[i] * (pow(3, i + 1) + i * pow(3, i - 1));
            }
            cout<< cost << endl; 
        }
    }
    return 0;
}