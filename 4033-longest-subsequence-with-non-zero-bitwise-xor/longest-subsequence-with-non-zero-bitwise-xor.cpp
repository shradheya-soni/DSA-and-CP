class Solution {
public:

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> ind(100,{1e9,-1});

        int ans = 0;
        for(int i = 0;i<64;i++){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(nums[j]&(1LL<<i)){
                    cnt++;
                    ind[i].first = min(ind[i].first,j);
                    ind[i].second = max(ind[i].second,j);

                }
                
            }
            if(cnt %2 == 1){
                return n;
            }
            else if (cnt >= 2){
                ans = max(ans,n-1);
            }
        }
        return ans;
    }
};