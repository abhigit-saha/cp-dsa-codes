// struct UnionFind { 
//     int n, set_size, *parent, *rank; 
//     UnionFind(){}; 
//     UnionFind(int a) { 
//         n = set_size = a; 
//         parent = new int[n+1]; 
//         rank = new int[n+1]; 
//         for(int i = 1; i<=n; i++) { 
//             parent[i] = i; 
//             rank[i] = 1; 
//         }
//     }

//     int find(int x) { 
//         if(x!=parent[x]) { 
//             return parent[x] = find(parent[x]); 
//         }

//         return x; 
//     }

//     int merge(int x, int y) { 
//         int xroot = find(x), yroot = find(y); 
//         if(xroot == yroot) return; 
//         if(rank[xroot]>rank[yroot]) { 
//             parent[yroot] =x; 
//             rank[xroot]+=rank[yroot];
//         }else { 
//             parent[xroot] = y; 
//             rank[yroot]+=rank[xroot]; 
//         }
//         set_size--; 
//     }
// }; 

struct UnionFind{ 
    int n, set_size, *rank, *parent; 
    UnionFind(){};
    UnionFind(int a) { 
        set_size = n = a; 
        rank = new int[n+1]; 
        parent = new int[n+1] ; 
        for(int i = 1; i<=n; i++) { 
            rank[i] = 1; 
            parent[i] = i; 
        }
    }
    int find(int x) { 
        if(parent[x]!=x) { 
            return parent[x] = find(parent[x]); 
        }

        return x; 
    }

    void merge(int x, int y) { 
        int xroot = find(x), yroot = find(y); 
        if(xroot==yroot) return; 
        if(rank[xroot]> rank[yroot]) { 
            parent[yroot] = x; 
            rank[xroot]+=rank[yroot]; 
        }else { 
            parent[xroot] = y; 
            rank[yroot]+=rank[xroot];
        }

        set_size--; 
    }
}; 