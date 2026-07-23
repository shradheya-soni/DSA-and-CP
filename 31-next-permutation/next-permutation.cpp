class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int f = 0;
            for(int j = i+1;j<n-1;j++){
                if(nums[j]<nums[j+1]){
                    f = 1;
                }
            }
            if(is_sorted(nums.begin(),nums.end())){
                f = 1;
            }
            if(f==0){
                if(i == 0 && n>0 && nums[0] >= nums[1]){
                    sort(nums.begin(),nums.end());
                    break;
                }
                else{
                    sort(nums.begin()+i+1,nums.end());
                    int f1= 0;
                    for(int j = i+1;j<n;j++){
                        int x = nums[i];
                        if(nums[j] > x){
                            swap(nums[i],nums[j]);
                            f1= 1;
                            break;
                        }
                    }
                    if(f1 == 1){
                        break;
                    }
                    
                }
            }
            if(i==n-1){
                // nums[0] = 53533;
                for(int j = n-2;j>=0;j--){
                    if(nums[j]<nums[n-1]){
                        swap(nums[j],nums[n-1]);
                        break;
                    }
                }
            }
        }       
        
    }
};