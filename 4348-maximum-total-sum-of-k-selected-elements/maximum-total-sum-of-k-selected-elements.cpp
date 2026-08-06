class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long num = 0;
        for(int i = 0;i<min(k,(int)nums.size());i++){
            long long temp = (long long) mul*nums[i];
            if(mul > 0) num = num +  temp;
            else num += nums[i];
            mul--;
        }
        return num;
    }
};