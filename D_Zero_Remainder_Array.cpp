#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k; 
        cin >> n >> k;
        
        multiset<int> mst;
        
        for(int i = 0; i < n; i++) {
            int el;
            cin >> el;
            
            int mod = el % k;
            
            if(mod == 0) continue;
            
            mst.insert((k - mod) % k);
        }
        
        int x = 0;
        while(mst.size()) {
            auto it = mst.lower_bound(x%k); 
            if(it!=mst.end()) { 
                x+=(*it-x%k); 

            }else { 
                it = mst.begin(); 
                x+=(k-x%k)+*it; 

            }
            mst.erase(it); 

            x++; 

        }
        
        cout << x << endl;
    }
    return 0;
}