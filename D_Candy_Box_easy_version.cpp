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
        map<int, int> freq; 
        for(int i = 0; i<n; i++) { 
            cin>> arr[i]; 
            freq[arr[i]]++; 
        }

        multiset<int, greater<int>> mst; 
        for (auto [el, frq]: freq) { 
            mst.insert(frq); 
        }

        int freqs = 1e9; 
        int ans = 0; 
        for(auto f: mst) { 
            if(freqs==0)break; 
            freqs = min(freqs, f); 
            ans+=freqs; 
            freqs--; 
        }

        cout<< ans << endl; 




    }
    return 0;
}