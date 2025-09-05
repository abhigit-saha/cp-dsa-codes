#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int msb(int el) { 
    int bit = -1; 
    int temp = el; 
    while(temp) { 
        temp>>=1; 
        bit++; 
    }
    
    return bit; 
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, l, r, k; cin>> n>> l >> r >> k; 
        if(n%2) { 
            cout<< l << endl; 
        }else { 
            int bit = msb(l) + 1; 
            int last = (1LL)<<(bit); 
            if(last>r) cout<< -1 << endl; 
            else if(n==2)cout << -1 << endl; 
            else { 
                
                if(k>n-2) cout<< last << endl; 
                else cout<< l << endl; 
            }
        }
    }
    return 0;
}