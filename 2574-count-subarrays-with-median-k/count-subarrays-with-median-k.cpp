class Solution {
public:
   
    int countSubarrays(vector<int>& nums, int k) {
        vector<int> arr(nums.size(),0);
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < k) arr[i] =-1;
            if(nums[i] > k) arr[i] = 1;

        }

        vector<int> pre = arr;
        for(int i = 1;i<nums.size();i++){
            pre[i] += pre[i-1];
        }
        map<int,int> mpp;
        map<int,int> temp;
        temp[0] = 1;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(arr[i]==0){
                for(auto it : temp){
                    mpp[it.first] += it.second;
                }
                temp.clear();
                
            }

            if(mpp.find(pre[i]) != mpp.end()){
                ans += mpp[pre[i]];
            }
            if(mpp.find(pre[i]-1) != mpp.end()){
                ans += mpp[pre[i]-1];
            }
            
            temp[pre[i]]++;
            
        }
        return ans;
        
        



    }
};