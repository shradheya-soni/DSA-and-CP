using ll = long long;
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<ll,ll>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
      
        }
        

        vector<vector<ll>> dist(n, vector<ll>(k + 1, 1e18)); 
        
  
        set<pair<ll, pair<int, int>>> st; 
        
        dist[0][1] = 0;
        st.insert({0, {0, 1}});
        
        while(!st.empty()){
            auto temp = *st.begin();
            st.erase(st.begin());
            
            ll d = temp.first;
            int node = temp.second.first;
            int f = temp.second.second;

            if(node == n - 1) return d;

            if(dist[node][f] < d) continue;

            for(auto it : adj[node]){
                int v = it.first;
                int w = it.second;

                int new_f = (labels[node] == labels[v]) ? f + 1 : 1;
                
                if(new_f <= k && dist[v][new_f] > d + w){
                    dist[v][new_f] = d + w;
                    st.insert({d + w, {v, new_f}});
                }
            }
        }
        return -1;
    }
};