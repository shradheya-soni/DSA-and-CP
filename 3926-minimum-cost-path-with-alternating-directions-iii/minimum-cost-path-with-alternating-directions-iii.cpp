#define ff first
#define ss second
class Solution {
public:
    long long dijkastra(vector<vector<int>>& penalty){
        long long n= penalty.size();
        long long m = penalty[0].size();
        vector<long long> dx = {1,-1,0,0};
        vector<long long> dy = {0,0,1,-1};
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(m,vector<long long>(2,1e18)));
        set<pair<pair<long long,long long>,pair<long long,long long>>> st;
        dp[0][0][1] = 1;
        
        st.insert({{1,1},{0,0}});
        while(!st.empty()){
            auto temp = *st.begin();
            st.erase(temp);
            long long dist = temp.ff.ff;
            long long turn = temp.ff.ss;
            long long x = temp.ss.ff;
            long long y = temp.ss.ss;
            auto num = temp;
            for(int i = 0;i<4;i++){
                long long nx = x + dx[i];
                long long ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    
                    if((i)%2 == 1-turn && dist+((nx+1)*(ny+1)) < dp[nx][ny][1-turn]){
                       
                        if(dp[nx][ny][1-turn] != 1e9){
                            st.erase({{dp[nx][ny][1-turn],1-turn},{nx,ny}});
                        }
                        dp[nx][ny][1-turn] = dist+((nx+1)*(ny+1));
                        st.insert({{dp[nx][ny][1-turn],1-turn},{nx,ny}});
                    }
                    
                    else if(dist+((nx+1)*(ny+1))+penalty[x][y] < dp[nx][ny][1-turn]){
                        
                        if(dp[nx][ny][1-turn] != 1e9){
                            st.erase({{dp[nx][ny][1-turn],1-turn},{nx,ny}});
                        }
                        dp[nx][ny][1-turn] = dist+((nx+1)*(ny+1))+penalty[x][y];
                        st.insert({{dp[nx][ny][1-turn],1-turn},{nx,ny}});
                    }
                    
                    
                }
            }
            if(dist+penalty[x][y] < dp[x][y][1-turn]){
                       
                if(dp[x][y][1-turn] != 1e9){
                    st.erase({{dp[x][y][1-turn],1-turn},{x,y}});
                }
                dp[x][y][1-turn] = dist+penalty[x][y];
                st.insert({{dp[x][y][1-turn],1-turn},{x,y}});
            }
            
        }

        return min(dp[n-1][m-1][1],dp[n-1][m-1][0]);
    }

    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        return dijkastra(penalty);
    }
};