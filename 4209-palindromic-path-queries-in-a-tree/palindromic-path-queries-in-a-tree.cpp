#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> seg;
    vector<int> lazy;
    vector<pair<int, int>> mpp;
    vector<vector<int>> up;
    vector<int> depth;
    int timer;

    void propagate(int i, int j, int ind) {
        if (lazy[ind] != 0) {
            seg[ind] ^= lazy[ind]; // XOR flips the parity
            if (i != j) {
                lazy[ind * 2 + 1] ^= lazy[ind];
                lazy[ind * 2 + 2] ^= lazy[ind];
            }
            lazy[ind] = 0;
        }
    }

    void update(int i, int j, int l, int r, int ind, int val) {
        propagate(i, j, ind);
        
        if (r < i || l > j) return;
        
        if (l <= i && j <= r) {
            lazy[ind] ^= val;
            propagate(i, j, ind);
            return;
        }
        
        int mid = i + (j - i) / 2;
        update(i, mid, l, r, ind * 2 + 1, val);
        update(mid + 1, j, l, r, ind * 2 + 2, val);
    }

    int point_query(int i, int j, int pos, int ind) {
        propagate(i, j, ind);
        if (i == j) return seg[ind];
        
        int mid = i + (j - i) / 2;
        if (pos <= mid) return point_query(i, mid, pos, ind * 2 + 1);
        else return point_query(mid + 1, j, pos, ind * 2 + 2);
    }

    void dfs(int node, int par, int d, vector<vector<int>> &adj) {
        depth[node] = d;
        up[node][0] = (par == -1 ? node : par);
        for (int j = 1; j < 20; j++) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }
        mpp[node].first = timer++;
        for (int neighbor : adj[node]) {
            if (neighbor != par) dfs(neighbor, node, d + 1, adj);
        }
        mpp[node].second = timer - 1;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int j = 19; j >= 0; j--) {
            if (depth[u] - (1 << j) >= depth[v]) u = up[u][j];
        }
        if (u == v) return u;
        for (int j = 19; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        mpp.assign(n, {0, 0});
        up.assign(n, vector<int>(20, 0));
        depth.assign(n, 0);
        timer = 0;

        dfs(0, -1, 0, adj);

        int m = timer; 
        seg.assign(4 * m + 5, 0);
        lazy.assign(4 * m + 5, 0);

        // Build the Segment Tree initially
        for (int i = 0; i < n; i++) {
            int bit = 1 << (s[i] - 'a');
            update(0, m - 1, mpp[i].first, mpp[i].second, 0, bit);
        }

        vector<bool> result;

        for (const string &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update" || type[0] == 'u') {
                int node;
                char new_char;
                ss >> node >> new_char;

                if (s[node] != new_char) {
                    // XORing old char removes it, XORing new char adds it
                    int mask = (1 << (s[node] - 'a')) ^ (1 << (new_char - 'a'));
                    update(0, m - 1, mpp[node].first, mpp[node].second, 0, mask);
                    s[node] = new_char;
                }
            } else {
                int u, v;
                ss >> u >> v;

                int lca = get_lca(u, v);
                int mask_u = point_query(0, m - 1, mpp[u].first, 0);
                int mask_v = point_query(0, m - 1, mpp[v].first, 0);
                
                // mask_u ^ mask_v perfectly gives path parity EXCEPT the LCA is completely erased.
                // We XOR the LCA back in once so it is included in the path.
                int path_mask = mask_u ^ mask_v ^ (1 << (s[lca] - 'a'));
                
                // __builtin_popcount instantly counts the number of 1s (odd frequencies)
                result.push_back(__builtin_popcount(path_mask) <= 1);
            }
        }

        return result;
    }
};