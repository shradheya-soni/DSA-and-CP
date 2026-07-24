class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,1);
        vector<int> suf(n,1);
        pre[0] = nums[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1]*nums[i];
        }
        suf[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            suf[i] = suf[i+1]*nums[i];
        }
        vector<int> ans(n,1);
        for(int i = 0;i<n;i++){
            int p = 1;
            if(i-1 >=0 ){
                p*=pre[i-1];
            }
            if(i+1<n){
                p*=suf[i+1];
            }
            ans[i] = p;
        }
        return ans;
    }
};