class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0;i<n;i++){
            while(nums[i]-1ll >=0ll && nums[i]-1ll <n && nums[i] != nums[nums[i]-1ll]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int ind =-1;
        
        for(int i = 0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};