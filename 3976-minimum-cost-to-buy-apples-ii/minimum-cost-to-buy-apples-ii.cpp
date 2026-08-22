struct node{
    long long v,c, t;
    node(){
        v = 0,c=  0,t = 0;
    }
    node(long long a,long long b,long long d){
        v = a;
        c = b;
        t = d;
    }

};
class Solution {
public:
    
    void dijkastra1(int root,vector<vector<node>>& adj,vector<long long> &dist,int s){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> st;
        st.push({0,root});
        dist[root] = 0;

        while(!st.empty()){
            auto temp = st.top();
            st.pop();

            for(auto it : adj[temp.second]){
                if(dist[it.v] > temp.first + it.c * (s==1?(it.t):1)){
                    
                    dist[it.v] = temp.first + it.c * (s==1?(it.t):1);
                    st.push({dist[it.v],it.v});
                }
            }
        }
    }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<node>> adj(n+1,vector<node>());
        for(auto it : roads){
            long long u = it[0];
            long long v = it[1];
            long long c = it[2];
            long long t = it[3];

            adj[u].push_back(node(v,c,t));
            adj[v].push_back(node(u,c,t));

        }
        vector<int> ans;
           vector<long long> dist1(n,1e18);
            vector<long long> dist2(n,1e18);
        for(long long i = 0;i<n;i++){
         

            
            dijkastra1(i,adj,dist1,0);
            dijkastra1(i,adj,dist2,1);
            long long mini = 1e18;
            for(int j = 0;j<n;j++){
               
                mini = min({mini,dist1[j]+dist2[j]+prices[j]});
            }
            fill(dist1.begin(), dist1.end(), 1e18);
            fill(dist2.begin(), dist2.end(), 1e18);
            ans.push_back((int)mini);
        }
        return ans;
    }
};