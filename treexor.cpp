#include <bits/stdc++.h> 
using namespace std;

#define endl "\n"
#define int long long

struct Node { 
    Node* children[2]; 
    int cnt; 
    bool isEnd; 
    Node() { 
        cnt = 0; 
        isEnd =false; 
    }
}; 
vector<vector<int>> g; 

class BitTrie { 
    Node* root; 
    vector<vector<pair<int, int>>> treequeries; 
    vector<int> ans; 
    BitTrie(int q, const vector<vector<pair<int, int>>>& queries) { 
        treequeries = queries; 
        ans.clear(); 
        ans.resize(q); 
    }
    void insert(int num) { 
        Node* node = root; 
        for(int i = 30; i>=0; i--) { 
            int bit = (num&(1<<i))? 1: 0; 
            if(!node->children[bit]) { 
                node->children[bit] = new Node(); 
            }
            node = node->children[bit]; 
            node->cnt++; 
        }

        node->isEnd = true; 
    }

    void del(int num) { 
        Node* node = root; 
        for(int i = 30; i>=0; i--) { 
            int bit = (num&(1<<i)? 1: 0); 
            node = node->children[bit]; 
            node->cnt--; 
        }
    }

    int maxxor(int num) { 
        Node *node = root; 
        int ans = 0; 
        for(int i = 30; i>=0; i--) { 
            int bit = (num&(1<<i)? 1: 0); 
            if(!node->children[1^bit] || (node->children[1^bit]->cnt==0)) { 
                node = node->children[bit]; 
            }else { 
                node = node->children[1^bit];
                ans+=(1<<i);  
            }
        }
        return ans; 
    }
    void dfs(int val, int par) { 
        insert(val); 
        if(treequeries[val].size()) { 
            for(auto [k, i]: treequeries[val]){ 
                ans[i] = maxxor(val); 
            }
        }
        for(auto v: g[val]) { 
            if(v==par) continue; 
            dfs(v, val); 
        }
        del(val); 
    }
}; 


signed main () { 
    
}