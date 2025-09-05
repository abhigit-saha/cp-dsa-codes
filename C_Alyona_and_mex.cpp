#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t=1;
    while(t--) {
        int n, m;cin>> n>> m;  
        int minmex = 1e9; 
        while(m--) { 
            int l,r;cin>> l>> r; 
            minmex = min(minmex, r-l+1);
        }  

        cout<<minmex<<endl;
        vector<int> ans(n); 
        for(int i = 0; i<n; i++) { 
            ans[i] = i%minmex;  
            cout<<ans[i] << " ";
        }  

        cout<< endl; 
        

    }
    return 0;
}