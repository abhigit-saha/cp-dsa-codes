#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, c;cin>> n>> c;
        vector<int> b; 
        for(int i = 0; i< n; i++) { 
            int el;cin>> el; 
            if(el<=c) b.push_back(el); 
        }
        int ans = 0; 
        sort(b.begin(), b.end()); 
        reverse(b.begin(), b.end()); 
        int mult = 1; 
        for(int i = 0; i<b.size(); i++) { 
            if(mult*b[i]<=c) mult*=2; 
            else ans+=1; 
        }
        ans+=(n-b.size()); 
        cout<< ans << endl; 
    }
    return 0;
}