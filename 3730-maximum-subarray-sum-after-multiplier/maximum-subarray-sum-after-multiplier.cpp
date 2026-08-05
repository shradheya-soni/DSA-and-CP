using ll = long long;
class Solution {
public:

    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<pair<long long,int>> arr;
        int n = nums.size();
        vector<long long > brr(n,0);
        for(int i = 0;i<n;i++) brr[i] = nums[i];
        ll ans = -1e16;
        auto solve = [&](int mul){
            ll dp0 = 0;
            ll dp1 = -1e16;
            ll dp2 = -1e16;

            for(auto it : brr){
                ll val = mul?it*k:it/k;
                ll ndp0 = max(dp0 + it,it);
                ll ndp1 = max({val,dp1+val,dp0+val});
                ll ndp2 = max({it,dp1+it,dp2+it});
                ans = max({ans,ndp1,ndp2});

                dp0 = ndp0;
                dp1 = ndp1;
                dp2 = ndp2;

            }
        };
        solve(1);
        solve(0);

        return ans;

    }
};