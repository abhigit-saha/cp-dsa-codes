#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin>> n; 
        vector<int> arr(n); 
        for(int i = 0; i<n; i++) { 
            cin>> arr[i]; 
        }
        sort(arr.begin(), arr.end()); 
        int ans = 0; 
        for(int i = n-1; i>=0; i-=2) { 
            ans+=arr[i]; 
        }
        cout<< ans << endl; 
    }
    return 0;
}