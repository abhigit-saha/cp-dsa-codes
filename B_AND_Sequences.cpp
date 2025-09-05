#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod = 1e9+7; 
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n; cin>> n; 
        map<int, int> freq; 
        int minm = 1e9; 
        int alland = -1; 
        for(int i = 0; i<n; i++) { 
            int el;cin>> el; 
            if(alland==-1) alland = el; 
            else alland&=el; 
            freq[el]++; 
        }
        int ans = 1; 
        if(freq[alland]<2) { 
            cout<< 0 << endl; 
        }else { 
            int minf = freq[alland]; 
            int mult = ((minf%mod)*((minf-1)%mod))%mod; 
            ans = ((ans%mod) * (mult%mod))%mod; 
            int rem = n-2; 
            int fact = 1; 
            for(int i = 1; i<=rem; i++) { 
                fact = ((fact%mod)*(i%mod))%mod; 
            }

            ans = ((ans%mod)*(fact%mod))%mod;
            
            cout<< ans << endl; 

        }

    }
    return 0;
}