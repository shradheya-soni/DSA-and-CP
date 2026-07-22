class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0] = 1;
        int n = nums.size();

        vector<int> pre(n);pre[0] = nums[0];
        
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
            
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(mpp.find(pre[i]-k) != mpp.end()){
                ans += mpp[pre[i]-k];
            }
            mpp[pre[i]]++;
        }
        return ans;
    }
};