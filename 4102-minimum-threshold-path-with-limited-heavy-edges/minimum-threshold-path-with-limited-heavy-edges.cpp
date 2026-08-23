#define ll long long
class Solution {
public:

    bool dijkastra(ll threshold,ll k,vector<vector<pair<ll,ll>>>&adj,ll s,ll e,vector<ll> &dist){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        dist[s] = 0;
        pq.push({0,s});

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            for(auto it : adj[temp.second]){
                if(dist[it.first] > temp.first + (it.second > threshold)){
                    dist[it.first] = temp.first + (it.second > threshold);
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return (dist[e]<=k);

    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<vector<pair<ll,ll>>> adj(n,vector<pair<ll,ll>>());
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});

        }

        ll l = -1;
        ll r = 1e9+5;
        vector<ll> dist(n,1e9);
        while(l+1<r){
            ll mid = l + (r-l)/2;
            fill(dist.begin(),dist.end(),1e9);
            if(dijkastra(mid,k,adj,source,target,dist)){
                r = mid;
            }
            else l = mid;
        }
        if(r == 1e9+5){
            return -1;
        }
        return (int)r;

    }
};