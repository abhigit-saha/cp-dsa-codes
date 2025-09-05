#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;cin>> n>> m; 
        int lo = 1, hi = 2*m, ans = 2*m; 
        vector<int> jobs(n+1); 
        for(int i = 0; i<m; i++) { 
            int worker; cin>> worker; 
            jobs[worker]++; 
        }
        while(lo<=hi) { 
            int mid = lo+(hi-lo)/2; 
            int sumcompl = 0, sumleft = 0; 
            for(int i = 1; i<=n; i++) { 
                int first = min(mid, jobs[i]); 
                int second = (mid-first)/2; 
                int left = jobs[i]-first; 
                sumcompl+=second; 
                sumleft+=left; 

            }
            if(sumcompl>=sumleft){ 
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