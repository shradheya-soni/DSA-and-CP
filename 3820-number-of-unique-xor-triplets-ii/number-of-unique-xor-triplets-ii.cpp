class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxi = 3000;
        vector<int> st(5000,0);
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                st[(nums[i]^nums[j])] = 1;
            }
        }
        // map<int,int> mpp;
        vector<int> st1(3000,0);
        for(int i = 0;i<=maxi;i++){
            for(int j = 0;j<n;j++){
                if(st[(i^nums[j])] != 0){
                    // mpp[i]++;
                    st1[i] =1;
                }
            }
        }
        int s = accumulate(st1.begin(),st1.end(),0);
        return s;

    }
};