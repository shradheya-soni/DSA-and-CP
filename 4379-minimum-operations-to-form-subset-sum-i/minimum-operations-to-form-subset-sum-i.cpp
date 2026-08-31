class Solution {
public:
    int dp[101][5001];
    int f(int i, int sum, vector<int>& nums) {
        if(sum < 0) return 1e9;
        if (sum == 0) return 0;
        if (i == nums.size()) return 1e9;

        if (dp[i][sum] != -1) return dp[i][sum];

        
        int ans = 1e9;
        ans = min(ans,f(i + 1, sum, nums));
        int x = nums[i];
        
        int cost = 0;
        
        while(sum-x >= 0){
            ans = min(ans,cost + f(i + 1, sum-x, nums));
            x*=2;
            cost ++;

        }
        x = nums[i];
        cost = 0;
        while(x > 0){
            ans = min(ans,cost + f(i + 1, sum-x, nums));
            x/=2;
            cost ++;
        }
        
        return dp[i][sum] = ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
     
        int ans = f(0,sum,nums);
        if(ans == 1e9) return -1;
        return ans;
    }
};