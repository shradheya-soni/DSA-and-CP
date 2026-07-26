class Solution {
public:
int mod = 1e9 +7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int ones = 0;
        int zeros = 0;
        int n = nums.size();
        vector<int> arr(n,0);
        for(int i = 0;i<n;i++){
            if(nums[i] > b) arr[i] = 1;
            if(nums[i] < a) arr[i] = -1,ones++;
            else zeros++;
        }
        int num = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] == -1){
                ans = (ans + i-num)%mod;
                num++;
            }
        }
        vector<int> brr;
        for(int i = 0;i<n;i++){
            if(arr[i]>=0){
                brr.push_back(arr[i]);
            }
        }
        num = 0;
        for(int i = 0;i<brr.size();i++){
            if(brr[i] == 0){
                ans = (ans + i-num)%mod;
                num++;
            }
        }

        return ans%(mod);
    }
};