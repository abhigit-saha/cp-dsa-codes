#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin>> n; 
        vector<int> arr(n); 
        bool ans = true; 
        vector<int> minm(n); 
        for(int i = 0; i<n; i++) { 
            cin>>arr[i];  
            if(i==0)minm[i] = arr[i]; 
            else minm[i] = min(minm[i-1], arr[i]); 
            
        }
        for(int i = 1; i<n; i++) { 
            if(arr[i]>2*minm[i-1]-1) { 
                ans = false; 
                break; 
            }
        }
        
        cout<< ( ans ? "YES" : "NO" ) << endl; 
    }
    return 0;
}