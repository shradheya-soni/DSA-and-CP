class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        
        set<tuple<long long, long long, int>> st;
        

        vector<long long> max_power(n, -1);

        st.insert({0, -power, source});

        while (!st.empty()) {
            auto it = st.begin();
            auto [d, neg_p, u] = *it;
            long long p = -neg_p;
            st.erase(it); 
            if (u == target) return {d, p};

            if (p <= max_power[u]) continue;
            max_power[u] = p;

            long long next_power = p - cost[u];
            if (next_power < 0) continue; 

            for (const auto& [v, t] : adj[u]) {
                st.insert({d + t, -next_power, v});
            }
        }

        return {-1, -1};
    }
};