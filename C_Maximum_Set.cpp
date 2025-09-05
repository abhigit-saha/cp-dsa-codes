#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int power(int a, int b) { 
    if(b==1) return a; 
    if(b==0) return 1; 
    if(b%2==1) { 
        return a*power(a, b-1); 
    }
    int half = power(a, b/2);
    return half*half;  
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int l, r; cin>> l>> r; 
        int sz = 1.0*log2(r)-1.0*log2(l)+1; 
        int cnt = 0; 
        int d=2; 
        int maxa = r/power(d, sz-1); 
        cnt+=(maxa-l+1); 
        if(sz>=2) { 
            maxa = r/(3*power(d, sz-2)); 
            if(maxa>=l)cnt+=(maxa-l+1)*(sz-1); 
        } 
        cout<<sz << " " << cnt<< endl; 
    }
    return 0;
}