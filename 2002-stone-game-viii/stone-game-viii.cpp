class Solution {
public:


    int stoneGameVIII(vector<int>& stones) {
        deque<int> dq;
        long long ans = 0;
        vector<int> pre(stones.size(),0);
        pre[0] = stones[0];
        for(int i = 1;i<stones.size();i++) pre[i] = pre[i-1] + stones[i];
        for(int i = 1;i<pre.size();i++){
            if(i>1){
                while(!dq.empty() && pre[i] > dq.back()){
                    dq.pop_back();
                }
            }
            dq.push_back(pre[i]);
        }
        int n = pre.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1e9));
        // 0 is for alice
        dp[n-1][0] = pre[n-1];
        dp[n-1][1] = pre[n-1];
        for(int i = n-2;i>=0;i--){
            dp[i][0] = max(dp[i][0],pre[i] - dp[i+1][1]) ;
            dp[i][0] = max(dp[i][0],dp[i+1][0]);
            dp[i][1] = max(dp[i][1],pre[i] - dp[i+1][0]) ;
            dp[i][1] = max(dp[i][1],dp[i+1][1]);
        }

        
        return dp[1][0];
    }
};