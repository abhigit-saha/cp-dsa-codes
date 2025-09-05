#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;cin>> n>> m;
        map<int, int> pow; 
        int temp = n; 
        while(temp%2==0){ 
            pow[2]++; 
            temp/=2; 
        }
        while(temp%5==0) { 
            pow[5]++; 
            temp/=5; 
        }

        int minm = (pow[5]<pow[2])? 5: 2;
        int maxm = minm==5? 2: 5; 
        int mult = 1;
        while(pow[minm]<pow[maxm] && mult<=m) { 
            
            if(mult*minm <=m){ 
                mult*=minm; 
                pow[minm]++; 
            } 

            else break; 
        }
        while(mult<=m) { 
            if(mult*10<=m) mult*=10; 
            else break; 
        }
        int maxmult = m/mult; 
        // cout<< maxmult << endl; 
        // cout<< n*(m/mult) << endl;
        cout<< n*mult*maxmult << endl;  
        
    }
    return 0;
}