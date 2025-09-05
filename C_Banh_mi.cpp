#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod = 1e9+7; 
signed main() {
    int t = 1; 
    // cin >> t;
    while(t--) {
        int n, q;
        cin>> n>> q; 
        string s; cin>> s; 
        vector<int> pref(n+1); 
        for(int i  = 0; i<n; i++) { 
            pref[i+1] = pref[i]+(s[i]=='1'); 
        }

        
        while(q--) { 
            int l, r; cin>> l>> r; 
            int x = pref[r]-pref[l-1]; 
            int y = r-l+1-x; 
            int ans = (1LL<<y) %mod; 
            ans*=((1LL<<x)-1)%mod;
            ans%=mod; 
            // ans=(ans*((1<<x-1)%mod))%mod; 
            cout<< ans << endl; 
        }
    }
    return 0;
}