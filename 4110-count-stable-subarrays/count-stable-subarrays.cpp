class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> l(n+1,0);
        vector<long long> r(n+1,0);
        for(int i = 1;i<n;i++){
            if(nums[i] >= nums[i-1]){
                l[i] = l[i-1];
            }
            else{
                l[i] = i;
            }
        }
        r[n-1] = n-1;
        for(int i = n-2;i>=0;i--){
            if(nums[i] <= nums[i+1]){
                r[i] = r[i+1];
            }
            else{
                r[i] = i;
            }
        }

        vector<long long> dp(n+5,0);
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            long long strt = l[i-1];
            dp[i] = (long long)((i-strt+1)*((i-strt)))/2ll;
            dp[i] += (strt>=0)?dp[strt]:0;
        }
        vector<long long> arr;
        for(auto it : queries){
            long long i = it[0];
            long long j = it[1];

            long long ans = 0;
            ans +=dp[j+1]-dp[i];
            ans -= (i-l[i])*(min(r[i],j) - i+1);
            arr.push_back(ans);
        }
        return arr;
    }
};