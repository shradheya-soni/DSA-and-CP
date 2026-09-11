class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    vector<vector<int>> dp;
    int check(int i,int j,int n,int m,vector<vector<int>> &arr,int val){
        if(i<n && j <m && i>=0 && j>=0 && val < arr[i][j]){
            return 1;
        }
        return 0;
    }
    int f(int x,int y,vector<vector<int>>& val){
        int n = val.size();
        int m = val[0].size();
        int maxi = -1;
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        for(int i = 0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(check(nx,ny,n,m,val,val[x][y])){
                maxi = max(maxi,1+f(nx,ny,val));
            }
        }
        if(maxi==-1){
            return dp[x][y] = 1;
        }
        return dp[x][y] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& val) {
        int n = val.size();
        int m = val[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        int maxi = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                f(i,j,val);
                maxi = max(dp[i][j],maxi);
            }
        }
        return maxi;
    }
};