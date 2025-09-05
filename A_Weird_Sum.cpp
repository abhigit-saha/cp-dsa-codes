#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
   
        int n,m;cin>> n>> m;
        map<int, multiset<int>> rs, cs;
        
        for(int i = 0; i<n; i++) { 
            for(int j = 0; j<m; j++) {
                int el;cin>> el;  
                rs[el].insert(i+1); 
                cs[el].insert(j+1); 
            }
        }
        int ans = 0; 
        for(auto [el, r]: rs) { 
            int k = r.size(); 
            int i = 0; 
            for(auto el: r) { 
                ans+=(2*i-k+1)*el; 
                i++; 
            }
            // cout<< "el: " << el << " : " ; 
            // for(auto el: r) { 
            //     // ans+=(2*i-k+1)*el; 
            //     // i++; 
            //     cout<< el << " "; 
            // }

            // cout<< endl; 
        }
        for(auto [el, c]: cs) { 
            int k = c.size(); 
            int i = 0; 
            for(auto el: c) { 
                ans+=(2*i-k+1)*el; 
                i++; 
            }
        }

        cout<< ans << endl; 




    return 0;
}