class Solution {
public:
int mod = 1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp (2005,vector<long long>(1005,0));
        for(int i = 0;i<=nums[0];i++){
            dp[0][i] = 1;
        }
        
        for(int i = 1;i<n;i++){
            
            vector<long long> pre(1005,0);
            pre[0] = dp[i-1][0];
            for(int j = 1;j<1001;j++){
                pre[j] = pre[j-1] + dp[i-1][j];
            }
            for(int k = 0;k<=nums[i];k++){
                    int a = k;
                    int b = nums[i] - k;
                    // int pa = j;
                    // int pb = nums[i-1] - j;
                    int prev = min(a,nums[i-1]+a-nums[i]);
                    
                    if(prev >= 0 && prev <=1000){
                        dp[i][a] = (dp[i][a] + pre[prev])%mod;
                    }
                }
            
        }
        int ans = 0;
        for(int i = 0;i<1001;i++){
            ans = (ans + dp[n-1][i])%mod;
            
        }
        return ans;
    }
};