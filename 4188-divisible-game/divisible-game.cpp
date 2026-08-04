class Solution {
public:
    int mod = 1e9+7;
    
    int divisibleGame(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());

        vector<int> spf(max_val + 1);
        for (int i = 2; i <= max_val; i++) spf[i] = i;

        for (int i = 2; i * i <= max_val; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= max_val; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

       
        vector<int> facs;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
        
            while (num > 1) {
                int prime = spf[num];
                facs.push_back(prime);
                
                while (num % prime == 0) {
                    num /= prime;
                }
            }
        }
        long long ans = -1e9;
        long long  k = 1e9;
        for(int i = 0;i<facs.size();i++){
            long long fac = facs[i];
            if(fac == 1) continue;
            vector<long long> arr(nums.size(),0ll);
            for(int j = 0;j<nums.size();j++) arr[j] = (long long)nums[j];
            for(int j = 0;j<nums.size();j++){
                if(arr[j]%fac != 0) arr[j] *= -1;
            }
            for(int j = 1;j<nums.size();j++){
                arr[j] += arr[j-1];
            }

            long long mini = 0;
            long long maxi = -1e9;
            for(int j =0 ;j<nums.size();j++){
                maxi = max(maxi,arr[j] - mini);
                mini = min(mini,arr[j]);
            }

            if(maxi == ans){
                k = min(k,fac);
            }
            if(maxi > ans){
                ans = maxi;
                k = fac;
            }
            
        }
        if(k == 1e9){
            long long sum = accumulate(nums.begin(),nums.end(),0ll);
            return (-2 +mod)%mod;
        }
        return (ans*k + mod)%mod;
    }
};