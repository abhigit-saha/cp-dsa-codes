#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t=1;
    while(t--) {
        
        int n;cin>> n;  
        int ai = 2; 
        for(int i = 1; i<=n; i++) { 

            int ans = (i+1)*(i+1)*i-ai/i; 
            cout<<ans<< endl;
            ai = (i+1)*i; 
        }
    } 
    return 0;
}