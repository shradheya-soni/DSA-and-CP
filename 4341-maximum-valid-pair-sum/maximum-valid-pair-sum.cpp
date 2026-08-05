class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> arr(n,0);
        arr[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            arr[i] = max(arr[i+1],(long long)nums[i]);
        }
        long long maxi = 0;
        for(int i = 0;i<n;i++){
            int ind = i+k;
            if(ind < n) maxi = max(maxi,(long long)nums[i] + arr[ind]);
        }
        return (int)maxi;
    }
};