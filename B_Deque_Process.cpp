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

        int l=0, r = n-1; 
        string ans; 
        for(int i = 1; i<=n; i++) { 
            if(i%2==0) { 
                if(arr[l]<=arr[r]){ 
                    ans.push_back('L'); 
                    l++; 
                }else { 
                    ans.push_back('R'); 
                    r--; 
                }
            }else { 
                if(arr[l]>=arr[r]){ 
                    ans.push_back('L'); 
                    l++; 
                }else { 
                    ans.push_back('R'); 
                    r--; 
                }

            }
        }
        cout<< ans << endl; 
    }
}