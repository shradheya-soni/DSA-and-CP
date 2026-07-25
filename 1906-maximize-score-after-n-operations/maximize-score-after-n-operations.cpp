class Solution {
public:
    int dp[15][20000][19];
    int f(int i,vector<int>&nums,int &mask,int picked){
        int n=nums.size()/2;
        int ans = 0;
        if(i>=2*n){
            return -1;
        }
        if(mask == (1<<(2*n)) -1 || __builtin_popcount(mask)/2 > n){
            return 0;
        }
        if(dp[i][mask][picked+1] != -1) return dp[i][mask][picked+1];
        for(int j=0;j<2*n;j++){
            if(picked != -1 && (mask&(1<<j)) == 0){
                mask |= (1<<j);
                ans = max(ans,((__builtin_popcount(mask)/2))*gcd(nums[j],nums[picked]) + f(i+1,nums,mask,-1));
                mask ^= (1<<j);

                ans = max(ans,f(i+1,nums,mask,picked));
            }
            else if((mask&(1<<j)) == 0){
                mask |= (1<<j);
                ans = max(ans,f(i+1,nums,mask,j));
                mask ^= (1<<j);
            }
        }

        return dp[i][mask][picked+1]= ans;

    }
    int maxScore(vector<int>& nums) {
        int num = 0;
        memset(dp,-1,sizeof(dp));
        return f(0,nums,num,-1)+1;
    }
};
