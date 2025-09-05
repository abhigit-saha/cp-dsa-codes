#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t =1; 
    while(t--) {
        int n, k; 
        cin>> n>> k; 
        vector<int> arr(n); 
        for(int i = 0; i<n; i++) { 
            cin>> arr[i]; 
        }

        sort(arr.begin(), arr.end()); 
        // reverse(arr.begin(), arr.end()); 
        vector<int> pref(n+1);
        for(int i = 0; i<n; i++) { 
            pref[i+1] = pref[i]+ arr[i]; 
        }
        int lo = 1, hi  = 1e9, ans = 1; 
        int sm = 1e9; 
        function<int(int)> check = [&](int cnt) { 
            for(int i = cnt-1; i<n; i++) { 
                int diffsum = pref[i+1]-pref[i-cnt+1];  
                if(arr[i]*cnt- diffsum<=k) { 
                    sm = arr[i]; 
                    return 1; 
                }
            }
            return 0; 
        };
        while(lo<=hi) { 
            int mid = lo + (hi-lo)/2; 
            if(check(mid)) { 
                ans = mid; 
                lo = mid+1; 
            }else { 
                hi = mid-1; 
            }
        }

        cout<<ans << " " << sm << endl;  
    }
    return 0;
}