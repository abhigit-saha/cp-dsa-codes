#include <bits/stdc++.h> 
using namespace std;

#define endl "\n"
#define int long long


signed main() { 
    int t; cin>> t; 
    while(t--) { 
        int n;cin>> n; 
        string s; cin>> s; 
        int sum = 0, cnt = 0; 
        vector<int> sheeps; 
        for(int i = 0; i<n; i++) { 
            if(s[i]=='*'){ 
                sheeps.push_back(i); 
            } 
        }

        int m = sheeps.size(); 
        if(m==0) { 
            cout<< 0 << endl; 

        }else { 
            int mid = sheeps[m/2]; 
            int st; 
            int ans = 0; 
            int it = m/2-1; 
            int cur = mid-1; 
            while(it!=-1) { 
                ans+=abs(cur-sheeps[it]); 
                // cout<< "added: " <<abs(cur-sheeps[it]) <<endl; 
                it--; 
                cur--; 
            }
            it = m/2+1;
            cur = mid+1;  
            while(it!=m) { 
                ans+=abs(cur-sheeps[it]); 
                // cout<< "added: " <<abs(cur-sheeps[it]) <<endl; 
                it++; 
                cur++; 
            }


            cout<< ans << endl; 
            // if(2*mid==m) { 
            //     st = mid-(m/2)+1; 
            // }else { 
            //     st = mid-m/2; 
            // }
            // vector<int> final; 
            // for(int i = st; i<st+m; i++) { 
            //     final.push_back(i); 
            // }
            // int ans = 0; 
            // for(int i = 0; i<m; i++) { 
            //     ans+=abs(final[i]-sheeps[i]); 
            // }
        }
        

        
        


    }
}