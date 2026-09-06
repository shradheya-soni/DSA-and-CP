class Solution {
public:
    int maxProfit(vector<int>&arr) {
        int n = arr.size();
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        int mini = 1e9;
        int maxi = 0;
        for(int i = 0;i<n;i++){
            mini = min(mini,arr[i]);
            dp1[i] = max((i-1>=0)?dp1[i-1]:0,arr[i] - mini);
        }
        for(int i = n-1;i>=0;i--){
            maxi = max(maxi,arr[i]);
            dp2[i] = max((i+1<n)?dp2[i+1]:0,maxi - arr[i]);
        }
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            ans  = max({ans,dp1[i]+dp2[i+1],dp1[i+1]});
        }
        return ans;
    }
};