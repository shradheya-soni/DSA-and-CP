class Solution {
public:
    vector<vector<long long>> dp;
    long long f(int i ,int prev,vector<int>&nums,string&s){
        int n = nums.size();
        if(i == n){
            return 0;
        }

        long long ans = 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        if(s[i] == '0'){
            ans = max(ans,f(i+1,0,nums,s));
        }
        else{
            if(prev == 0){
                ans = max(ans,f(i+1,1,nums,s) + nums[i]);
                if(i-1 >= 0) ans = max(ans,f(i+1,0,nums,s) + nums[i-1]);
            }
            else{
                ans = max(ans,f(i+1,1,nums,s) + nums[i]);
            }
        }

        return dp[i][prev] = ans;
        
    }
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        dp.assign(n+1,vector<long long>(2,-1));
        long long ans = f(0,0,nums,s);
        return ans;
    }
};