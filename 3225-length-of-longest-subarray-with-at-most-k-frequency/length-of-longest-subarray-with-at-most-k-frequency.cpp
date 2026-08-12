class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        map<int,int> mpp;
        for(int i = 0;i<n;i++){
            mpp[nums[i]] = 0;
        }
        int ans = 0;
        while(r<nums.size()){
            if(mpp[nums[r]] < k){
                ans = max(ans,r-l+1);
                mpp[nums[r]]++;

                r++;
                if(r == n) break;
            }
            else{
                mpp[nums[r]]++;

                if(r == n) break;
                while(mpp[nums[r]] > k){
                    mpp[nums[l]]--;
                    l++;
                    if(mpp[nums[l]] == 0){
                        mpp.erase(nums[l]);
                    }
                }
                r++;

            }
        }

        return ans;
    }
};