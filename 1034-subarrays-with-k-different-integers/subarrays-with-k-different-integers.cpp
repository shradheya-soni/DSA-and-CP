class Solution {
public:
    bool check(unordered_map<int,int> &mpp,int num,int k){
        mpp[num]++;
        if(mpp.size()<=k){
            mpp[num]--;
            return 1;
        }
        mpp[num]--;
        return 0;
    }
    void delulu(unordered_map<int,int>& mpp,int num){
        if(mpp.find(num) == mpp.end()){
            return;
        }
        mpp[num]--;
        if(mpp[num] == 0){
            mpp.erase(num);
        }

    }
    int f(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int n = nums.size();
        unordered_map<int,int> mpp;
        int ans = 0;
        while(l<=r && r<n){
            if(check(mpp,nums[r],k)){
                mpp[(nums[r])]++;
                ans += r-l+1;
                r++;
            }
            else{
                delulu(mpp,nums[l]);
                l++;
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = f(nums,k) - f(nums,k-1);
        return ans;
    }
};