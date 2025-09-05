#include <bits/stdc++.h> 
using namespace std;

#define endl "\n"
#define int long long

int n; 
vector<pair<int, int>> rng; 
bool check(int mid) { 
    int curl=0, curr = 0;  
    for(int i = 0; i<n; i++) { 
        curr = min(curr+mid, rng[i].second); 
        curl = max(curl-mid, rng[i].first);  
        if(curl>curr)return false; 
    }
    return true; 
}
signed main() { 
    int t;cin>> t;
    while(t--) {
        cin>> n;
        rng.clear(); 
        rng.resize(n); 
        int lo = 0, hi = 1e9, ans = 1e9; 
        for(int i = 0; i<n; i++) { 
            int l,r;cin>>l>>r; 
            rng[i] = {l, r}; 
        }
        while(lo<=hi) { 
            int mid = lo+(hi-lo)/2; 
            if(check(mid)) { 
                ans= mid; 
                hi = mid-1; 
            }else { 
                lo = mid+1; 
            }
        }

        cout<< ans<< endl; 
    }
}