#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin>> n; 
        map<int, int> freq; 
        bool ans = false; 
        for(int i = 0; i<n; i++) { 
            int el;cin>> el; 
            freq[el]++; 
        }
        for(auto [e, f]: freq) { 
            if(f>=2) { 
                ans = true; 
                break; 
            }
        }
        if(ans) { 
            cout<<"YES" << endl; 
        }else { 
            cout<<"NO" << endl; 
        }
    }
    return 0;
}