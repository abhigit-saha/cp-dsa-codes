#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;cin>> n>> m; 
        vector<int> a(n), b(n); a[0] = 1; 
        for(int i = 1; i<n; i++) cin>>a[i]; 
        for(int i = 0; i<n; i++) cin>> b[i]; 

        sort(a.begin(), a.end()); 
        sort(b.begin(), b.end()); 
        int lo = 0, hi = n, ans = hi; 
        while(lo<=hi) { 
            int mid = lo+(hi-lo)/2; 
            bool check = 1; 
            for(int i = 0; i<n-mid; i++) { 
                if(a[i]>=b[i+mid]) { 
                    check = 0; 
                    break;
                } 
            }

            if(check) { 
                ans = mid; 
                hi = mid-1; 
            }else { 
                lo = mid+1; 
            }
        }
        cout<< ans << endl; 
    
    }
    return 0;
}