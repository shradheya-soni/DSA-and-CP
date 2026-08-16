typedef long long ll;
class Solution {
public:
 
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();

        vector<vector<ll>> dp(nums.size()+5,vector<ll>(m+5,-1e16));
        vector<ll> arr(n,0);
        arr[0] = nums[0];
        for(int i = 1;i<n;i++) arr[i] = arr[i-1] + nums[i];

        for(int i = 0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int i = l-1;i<=r-1;i++){
            if(i >= 0){
                dp[i][1] = arr[i];
            }
        }

        for(int j = 1;j<=m;j++){
            deque<int> dq;
            for(int i = 0;i<n;i++){
                ll to_add = i-l;

                if(to_add >=0 ){
                    ll num = (-arr[to_add] +dp[to_add][j-1]);
                    while(!dq.empty() &&  (-arr[dq.back()] +dp[dq.back()][j-1]) < num){
                        dq.pop_back();
                    }
                    dq.push_back(to_add);
                }

                ll to_sub = i-r-1;
                if(!dq.empty() && dq.front() == i-r-1){
                    dq.pop_front();
                }

                if(!dq.empty()) {
                    int best_k = dq.front();
                    dp[i][j] = max(dp[i][j], arr[i] + dp[best_k][j-1] - arr[best_k]);
                }
              
                if (i > 0) {
                    dp[i][j] = max(dp[i][j],dp[i-1][j]);
                }
            }
            
        }
        
        
        ll maxi = -1e16;
        for(int i = 1;i<=m;i++){
            maxi = max(maxi,dp[n-1][i]);
        }
        return maxi;
    }
};