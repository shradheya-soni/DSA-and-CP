class Solution {
public:
    long long maxValue(vector<int>& nums) {
        vector<int> arr = nums;
        int n = arr.size();
        long long ans = 0;
        for(int i = 0;i<n;i++){
            if(i%2 == 0) arr[i] = -arr[i],ans += nums[i];
            else ans -= nums[i];
            cout<<arr[i]<<" ";
        }

        long long max_sum = 0; // Use a very small number for negatives
        long long min_pref_even = 0; 
        long long min_pref_odd = 1e18;
        long long curr_sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            curr_sum += arr[i];
          
            if ((i + 1) % 2 == 0) { 
                max_sum = max(max_sum, curr_sum - min_pref_even);
                min_pref_even = min(min_pref_even, curr_sum);
            } else { 
                max_sum = max(max_sum, curr_sum - min_pref_odd);
                min_pref_odd = min(min_pref_odd, curr_sum);
            }
        }
        
        return (ans + 2*max_sum);


    }
};