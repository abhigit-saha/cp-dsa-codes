#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int arr[100100]; 
int n, m, k; 
int dp[2][100100]; 

signed main() {
    cin>> n>> m>> k; 
    int prev =0, cur = 0; 
    vector<int> arr(n);
    int sum = 0;  
    multiset<int, greater<int>> mst; 
    int extra = 0; 
    for(int i = 0; i<n; i++) {
        cin>> arr[i]; 
        sum+=1; 
        if(i!=0) { 
            extra+=arr[i]-arr[i-1]-1; 
            mst.insert(arr[i]-arr[i-1]-1); 
        }
    }
    int lim = k-1; 
    for(auto el: mst){
        if(lim==0)break; 
        extra-=el; 
        lim--; 
    } 

    sum+=extra; 
    cout<< sum<< endl; 

    return 0;
}