#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;cin>> n>> m; 
        vector<char> s(n, 'a');
        string alpha = "abcdefghijklmnopqrstuvwxyz"; 
        if(m/pow(26, n-1)-1 >=26) { 
            cout<< -1 << endl; 
        }else { 
            for(int i = n-1; i>=0; i--) { 
                for(int x = 0; x<26; x++) { 
                    if(m-x*pow(26, i)<=pow(26, i)) { 
                        s[i] = alpha[x]; 
                        m-=x*pow(26, i); 
                        break; 
                        
                    }
                }
            }
        } 

        for(int i = n-1; i>=0; i--) { 
            cout<< s[i]; 
        }
        cout<< endl; 

        
    }
    return 0;
}