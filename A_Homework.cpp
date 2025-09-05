#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin>> n; 
        string a; cin>> a; 
        int m;cin>> m; 
        string b;cin>> b; 
        string c;cin>> c;
        for(int i = 0; i<m; i++) {
            if(c[i]=='V') { 
                a = b[i]+a; 
            }else { 
                a = a+b[i]; 
            }
        }
        cout<< a << endl; 
    }
    return 0;
}