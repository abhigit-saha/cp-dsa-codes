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
        int n;
        cin >> n;
        vector<int> a(n), b(n); 
        for(int i = 0; i<n; i++) { 
            cin>> a[i]; 
        }
        vector<int> pref(n+1), add(n+1), full(n+1); 
        // cout<<"Prefix: " << endl; 
        for(int i = 0; i<n; i++) { 
            cin>> b[i]; 
            pref[i+1] = pref[i]+ b[i]; 
            // cout<< pref[i] << " "; 
        }
        // cout<< endl; 



        for(int i = 0; i<n; i++) { 
            int j = upper_bound(pref.begin(), pref.end(), a[i]+pref[i])-pref.begin()-1; 
            // cout<< "upperbound: " << j<< " for " << a[i] + pref[i] << endl; 
            full[i]+=1; 
            full[j]-=1; 
            add[j]+=(a[i]-(pref[j]-pref[i])); 
        }

        for(int i = 0; i<n; i++) { 
            if(i)full[i]+=full[i-1]; 
            cout<< full[i]*b[i]+add[i]<< " "; 
        }
        cout<< endl; 
        

        

    } 
}