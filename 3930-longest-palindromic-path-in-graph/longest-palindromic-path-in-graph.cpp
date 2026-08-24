class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector<vector<int>> adj(n,vector<int>());
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<vector<vector<int>>> dp((1<<n)+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
        int maxi = 0;
        for(int i = 0;i<n;i++){
            maxi = 1;
            dp[1<<i][i][i] = 1;
        }
        for(int i = 0;i<n;i++){
            for(auto v : adj[i]){
                if(label[i] == label[v]){
                    dp[(1<<i)|(1<<v)][i][v] = 1;
                    maxi = 2;
                    dp[(1<<i)|(1<<v)][v][i] = 1;
                }
            }
        }
        for(int mask = 0;mask<(1<<n);mask++){
            for(int u = 0;u<n;u++)if(mask&(1<<u)){
                for(int v = 0;v<n;v++)if(mask&(1<<v)){
                    if(dp[mask][u][v]){
                        maxi = max(maxi,__builtin_popcount(mask));
                    
                        for(auto nu : adj[u])if(!(mask&(1<<nu))){
                            for(auto nv : adj[v])if((!(mask&(1<<nv)) )&& nu!=nv){
                                if(label[nu] == label[nv]){
                                    dp[mask|(1<<nu)|(1<<nv)][nu][nv] = 1;
                                    dp[mask|(1<<nu)|(1<<nv)][nv][nu] = 1;
                                    maxi = max(maxi,__builtin_popcount(mask)+2);

                                }
                            }
                        }
                    }
                }
            }
        }
        return maxi;
    }
};