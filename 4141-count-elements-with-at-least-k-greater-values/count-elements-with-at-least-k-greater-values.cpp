class Solution {
public:
    int countElements(vector<int>& nums, int k) {

        vector<int> arr= nums;
        sort(arr.begin(),arr.end());
        int ans = 0;
        for(int i = 0;i<arr.size();i++){
            int ind = upper_bound(arr.begin(),arr.end(),arr[i]) - arr.begin();
            if(arr.size()-ind >= k){
                ans++;
            }
        }
        
        return ans;
    }
};