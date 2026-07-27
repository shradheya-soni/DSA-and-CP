
class Solution {
public:
    unordered_map<string,vector<pair<string,int>>> adj;
    unordered_map<string,unordered_map<string,long long>> memo;

    long long dijkastra(string &start,string &end){
        if(memo[start].find(end) != memo[start].end()){
            return memo[start][end];
        }
        set<pair<long long,string>> st;
        st.insert({0,start});
        map<string,long long> dist;
        dist[start] = 0;

        while(!st.empty()){
            auto temp = *st.begin();
            st.erase(temp);
            for(auto it : adj[temp.second]){
                if(dist.find(it.first) == dist.end() || it.second + temp.first < dist[it.first]){
                    if(dist.find(it.first) != dist.end()){
                        st.erase({dist[it.first],it.first});
                    }
                    dist[it.first] = it.second + temp.first;
                    st.insert({dist[it.first],it.first});
                }
            }
        }

        if(dist.find(end) != dist.end()){
            memo[start][end] = dist[end];
            return dist[end];
        }

        else{ memo[start][end] =1e18 ;return 1e18;}
   }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        memo.clear();
        adj.clear();
        int n = source.length();
        int m = original.size();
        vector<long long> dp(n+5,1e18);
        for(int i = 0;i<original.size();i++){
            adj[original[i]].push_back({changed[i],cost[i]});
        }
        set<int> lens;
        for(int i = 0;i<original.size();i++){
            lens.insert(original[i].size());
        }
        
        for(int i = 0;i<n;i++){
            if(source[i] == target[i]){
                if(i>0) dp[i] = min(dp[i],dp[i-1]);
                else dp[i] = 0;
            }
            for(auto j = lens.begin();j!=lens.end();j++){
                int sz = *j;
                if(i-sz+1 >= 0){
                    int ind = i-sz+1;
                    string req = source.substr(ind,sz);
                    string b = target.substr(ind,sz);
                    if(dijkastra(req,b) < 1e18){
                        dp[i] = min(dp[i],dijkastra(req,b)+((i-sz>=0)?dp[i-sz]:0));
                    }
                }   
            }
            

        }
        if(dp[n-1] == 1e18) return -1;
        return dp[n-1];
        
    
    }
};