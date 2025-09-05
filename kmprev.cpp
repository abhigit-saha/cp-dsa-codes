#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    { 
        string s; 
        cin>> s; 
        int n = s.size();  
        vector<int> kmp(n+1);  
        kmp[0] = -1; 
        int j = -1, i = 0; 
        while(i<n) { 
            while(j!=-1 && s[i]!=s[j]) { 
                j = kmp[j]; 
            }
            i++; j++; 
            kmp[i] = j; 
        } 

        if(n%(n-kmp[n])==0) return true; 
        return false;  

    }
    return 0;
}