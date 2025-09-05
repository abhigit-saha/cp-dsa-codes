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
        int temp = n;

        vector<int> repr;
        while (temp)
        {
            repr.push_back(temp % 3);
            temp /= 3;
        }
        int ans = 0; 
        int cost = 0; 
        for (int i = 0; i < repr.size(); i++)
        {
            cost+=repr[i]*(pow(3, i+1)+i*pow(3, i-1));
        }
        cout<< cost << endl; 
    }
    return 0;
}