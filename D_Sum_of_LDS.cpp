#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
vector<int> arr; 
int dp[500500]; 
int n;
int rec(int level) { 
    if(level>=n)return 0; 
    if(level==n-1) return 1;
    if(dp[level]!=-1) return dp[level]; 

    int ans = 0; 
    if(level!=n-1) { 
        if(arr[level+1]>arr[level]) { 
            ans =rec(level+2) + (n-level); 
        }else { 
            ans = rec(level+1) + (n-level); 
        }
    }

    return dp[level] = ans; 

}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1,sizeof(dp)); 
        cin>> n;
        arr.clear(); 
        arr.resize(n); 

        for(int i = 0; i<n; i++) cin>> arr[i]; 
        rec(0); 
        int ans = 0; 
        for(int i = 0; i<n; i++) { 
            ans+=rec(i); 
        }

    
        
        cout<< ans << endl; 
    }
    return 0;
}