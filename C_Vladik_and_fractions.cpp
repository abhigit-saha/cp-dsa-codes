#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        if(n==1) { 
            cout<< -1<< endl; 
        }else { 
            cout << n << " " << n + 1 << " " << n * (n + 1) << endl;

        }
    }
    return 0;
}