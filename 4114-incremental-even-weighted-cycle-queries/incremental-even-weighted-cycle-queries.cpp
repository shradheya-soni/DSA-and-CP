#include <vector>
#include <algorithm>

using namespace std;

struct dsu {
    vector<int> parents, sz, color; 
    
    dsu(int n) {
        parents.resize(n + 1);
        sz.assign(n + 1, 1);
        color.assign(n + 1, 0); // 0 means same parity as root, 1 means different
        for (int i = 0; i <= n; i++) {
            parents[i] = i;
        }
    }

    int find_par(int u) {
        if (parents[u] == u) {
            return u;
        }
        int root = find_par(parents[u]);
        // Update color relative to the ultimate root
        color[u] ^= color[parents[u]];
        return parents[u] = root;
    }

    // Returns true if edge is successfully added
    bool union_by_size(int u, int v, int w) {
        int pu = find_par(u);
        int pv = find_par(v);

        if (pu == pv) {
            // Cycle detected. Add only if weight sum is even
            // (meaning existing path parity matches the new edge weight)
            return (color[u] ^ color[v]) == w; 
        }

        // Union by size
        if (sz[pu] < sz[pv]) {
            swap(pu, pv); 
        }

        parents[pv] = pu;
        sz[pu] += sz[pv];
        
        // Because XOR is commutative, this formula works perfectly 
        // regardless of whether we swapped pu and pv above.
        color[pv] = color[u] ^ w ^ color[v];
        
        return true;
    }
};

class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        dsu d(n);
        int cnt = 0;
        
        for (const auto& edge : edges) {
            if (d.union_by_size(edge[0], edge[1], edge[2])) {
                cnt++;
            }
        }
        
        return cnt;
    }
};