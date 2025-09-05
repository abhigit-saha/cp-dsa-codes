#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, x, y; 
        cin>> a>> b>> x>> y; 
        if(b-a==1 && a%2==0) { 
            cout<< min(x, y) << endl; 
        }else if(a-b==1 && a%2==1) { 

            cout<< y << endl; 
        }else if(b>=a) { 
            int ans = 0; 
            
            if(y<x) { 
                while(a!=b) { 
                    if(a%2==0) { 
                        a^=1; 
                        ans+=y; 
                    }else { 
                        a++; 
                        ans+=x; 
                    }
                } 
            }else { 
                ans+=(b-a)*x; 

            }


            cout<< ans << endl; 
        }else cout<< -1 << endl; 
        // if(a>b) { 
        //     if(a-b ==1) { 
        //         if(a%2==1)cout<< y << endl; 
        //     }
        //     else cout<< -1 << endl; 
        // }else { 
        //     if(a==b)cout<< 0 << endl; 
        //     else if(b-a==1) { 
        //         if(a%2==0) cout<< min(x, y) << endl; 
        //         else cout<< (b-a)*x << endl;  
        //     }
        //     else cout<< (b-a)*x << endl; 
        // }
    }
    return 0;
}