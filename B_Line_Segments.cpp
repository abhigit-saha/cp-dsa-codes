#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin>> n; 
        int x1, y1, x2, y2; 
        cin>> x1 >> y1 >> x2 >> y2; 

        int dist = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        float d = sqrt(dist); 
        vector<float> moves(n);
        float sum = 0; 
        for(int i = 0; i<n; i++) { 
            cin>> moves[i]; 
            sum+=moves[i]; 
        }
        sum+=d; 
        moves.push_back(d); 
        bool ans = true; 
        for(int i = 0; i<=n; i++) { 
            if(sum-moves[i]<moves[i]) { 
                ans = false; 
                break; 
            }
        }

        cout<< (ans ? "Yes": "No") << endl; 

    }
    return 0;
}