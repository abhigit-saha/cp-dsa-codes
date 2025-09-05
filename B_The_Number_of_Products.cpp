#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    // int t;
    // cin >> t;
    int n; cin>> n;
    vector<int> arr(n); 
    vector<int> negidx; 
    for(int i = 0; i<n; i++) { 
        cin>> arr[i]; 
    }
    int cnt1 = 0, cnt2 = 0; 
    int bal = 0; 
    int ansp = 0; 
    for(int i = 0; i<n; i++) { 

        if(bal%2==0) { 
            cnt1++; 
        }else { 
            cnt2++; 
        }
        if(arr[i]<0) bal++; 

        if(bal%2==0) { 
            ansp+=cnt1; 
        }else { 
            ansp+=cnt2; 
        }

        
    }

    int ansn = n*(n+1)/2-ansp; 
    cout<< ansn << " " << ansp << endl; 


    


    return 0;
}