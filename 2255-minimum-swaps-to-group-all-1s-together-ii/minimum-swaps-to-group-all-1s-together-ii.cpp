class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> arr = nums;
        int n = arr.size();
        vector<int> frnt(n,0);
        vector<int> bck(n);
        frnt[0] = nums[0];
        int ones = 0;
        for(int i = 1;i<n;i++) frnt[i] = frnt[i-1] + nums[i];
        for(int i = 0;i<n;i++){
            if(nums[i] == 1) ones ++;
        }
        int ans = 1e9;
        for(int i = 0;i<n;i++){
            int l = i;
            int r = (n-ones+i+1)%n;
            if(r == 0){
                ans = min(ans,ones-frnt[i]);
                continue;
            }
            int s = frnt[i] - frnt[r-1];
            if(r>=l) s = frnt[i] + frnt[n-1] - frnt[r-1];
            ans = min(ans,ones-s);
        }
        return ans;

        
    }
};