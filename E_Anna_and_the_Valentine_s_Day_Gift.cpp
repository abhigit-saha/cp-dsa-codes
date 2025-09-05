#include <bits/stdc++.h> 
using namespace std;

#define endl "\n"
#define int long long

signed main() { 
    int t;cin>>t;
    while(t--) { 

        int n, m;cin>> n>> m;
        vector<int> arr(n); 
        string total; 
        for(int i = 0; i<n; i++) { 
            string el; cin>> el; 
            total+=el; 
            arr[i] = stoi(el); 
        }
        int sz = total.size(); 
        vector<int> zeros(n); 
        for(int i = 0; i<n; i++) { 
            int cnt = 0; 
            while(arr[i]%10==0) { 
                cnt++; 
                arr[i]/=10; 
            }
            zeros[i] = cnt; 
        }
        sort(zeros.begin(), zeros.end()); 
        reverse(zeros.begin(), zeros.end());
        // for(int i = 0; i<n; i++) cout<< zeros[i] << " "; 
        // cout<< endl; 
        int dec = 0; 
        for(int i = 0; i<n; i+=2) { 
            dec+=zeros[i]; 
        }
        if(sz-dec<=m){ 
            cout<< "Anna" << endl; 
        }else { 
            cout<< "Sasha" << endl; 
        }
    }
}