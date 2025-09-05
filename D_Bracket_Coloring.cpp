#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        deque<char> dq; 
        int n;cin>> n; 
        int col = 1; 
        string s; cin>> s;
        char prev = '0'; 
        vector<int> cols(n); 
        for(int i = 0; i<n; i++) { 
            if(prev!='0' && dq.empty()) { 
                if(s[i]!=prev) { 
                    col = 3-col; 
                    prev = s[i]; 
                }
            }else if(dq.empty()) { 
                prev=s[i]; 
            }
            
            char c = s[i]; 
            if(s[i]=='(') { 
                if(!dq.empty() && dq.back() ==')') { 
                    dq.pop_back(); 
                }else { 
                    dq.push_back(s[i]); 
                }
            }else { 
                if(!dq.empty() && dq.front() =='(') { 
                    dq.pop_front(); 
                }else { 
                    dq.push_front(s[i]); 
                }

            }
            cols[i] = col; 

            
        }
        if(!dq.empty()) {
            cout<<-1 << endl;  

        }else { 
            set<int> st; 

            for(int i = 0; i<n; i++) st.insert(cols[i]); 
            cout<< st.size() << endl; 
            for(int i = 0; i<n; i++) cout << cols[i] << " "; 
            cout<< endl; 
        }
    }
    return 0;
}