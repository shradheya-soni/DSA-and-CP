class Solution {
public:
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pre(n,0);
        pre[0] = stoneValue[0];
        for(int i= 1;i<n;i++){
            pre[i]= pre[i-1] + stoneValue[i];
        }
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                for(int k = i;k<j;k++){
                    int suml = pre[k]- ((i>0)?pre[i-1]:0);
                    int sumr = pre[j] -((i>0)?pre[i-1]:0) - suml;
                    if(suml > sumr && k+1 <= j) dp[i][j] = max(dp[i][j],(dp[k+1][j] + sumr));
                    else if(suml < sumr) dp[i][j] = max(dp[i][j],dp[i][k] + suml);
                    else{
                        dp[i][j] = max(dp[i][j],(dp[k+1][j] + sumr));
                        dp[i][j] = max(dp[i][j],dp[i][k] + suml);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};