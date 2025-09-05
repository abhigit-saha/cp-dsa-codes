#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin>> n; 
        vector<int> x(n), y(n); 
        for(int i = 0; i<n; i++) { 
            cin>> x[i] >> y[i] ;
        }
        sort(x.begin(), x.end()); 
        sort(y.begin(), y.end()); 
        if(n%2) { 
            cout<< 1 << endl; 
        }else { 
            int ans = (x[n/2]-x[n/2-1]+1)*(y[n/2]-y[n/2-1]+1); 
            cout<< ans << endl; 
        }
    }
    return 0;
}