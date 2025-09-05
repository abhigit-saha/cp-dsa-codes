#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int arr[100100]; 
int n; 
int dp[100100]; 
int rec(int level) { 
    if(level>n)return 0; 
    if(level==n)return dp[n] = 1; 
    if(dp[level]!=-1) return dp[level]; 
    int ans  =1; 
    for(int x = 2; level*x<=n; x++) {
        if(arr[level*x]>arr[level])ans = max(ans, 1+rec(level*x)); 
    }
    return dp[level] = ans; 
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        cin>> n; 
        memset(dp, -1, sizeof(dp)); 
        for(int i = 1; i<=n; i++) { 
            cin>> arr[i]; 
        }
        int ans = 0; 
        for(int i = 1; i<=n; i++) ans=max(ans, rec(i)); 

        cout<< ans << endl; 
    }
    return 0;
}