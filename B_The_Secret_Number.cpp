#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int power(int a, int b) { 
    if(b==1) return a; 
    if(b==0) return 1; 
    if(b%2==1) { 
        return a*power(a, b-1); 
    }else { 
        return power(a, b/2)*power(a, b/2); 
    }
}
signed main() {
    int t;
    cin >> t;

    while(t--) {
        int n;cin>> n; 
        vector<int> ans; 
        for(int p = 1; power(10, p)+1<=n; p++) { 
            int d = power(10, p)+1; 
            // cout<< "d: " << d << endl; 
            if(n%d==0){ 
                ans.push_back(n/d); 
            }
        }
        reverse(ans.begin(), ans.end()); 
        cout<< ans.size() << endl; 
        if(ans.size()) { 
            for(int i = 0; i<ans.size(); i++) cout<< ans[i] << " " ; 
            cout<< endl; 
        }
        
    }
    return 0;
}