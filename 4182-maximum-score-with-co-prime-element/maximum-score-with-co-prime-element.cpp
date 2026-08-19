class Solution {
public: 
    vector<int> factor_maker(int n, vector<int>& primes) {
        vector<int> ans;
        int i = 0;
        // Optimized to sqrt(n) to prevent TLE
        while(i < primes.size() && primes[i] * primes[i] <= n) {
            if(n % primes[i] == 0) {
                ans.push_back(primes[i]);
                while(n % primes[i] == 0) n /= primes[i];
            }
            i++; 
        }
        if(n > 1) ans.push_back(n); 
        return ans;
    }

    int f(vector<int>& factors, vector<int>& freq) {
        int n = factors.size();
        int cnt = 0;
        // PIE must start from 1 (non-empty subsets)
        for(int i = 1; i < (1 << n); i++) {
            int num = 1;
            int temp = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    temp++;
                    num *= factors[j];
                }
            }
            if(temp % 2 == 1) cnt += freq[num];
            else cnt -= freq[num];
        }
        return cnt;
    }

    int maxScore(vector<int>& nums, int maxVal) {
        vector<int> freq(1e5 + 5, 0);
        int n = nums.size();
        vector<bool> in_array(1e5 + 5, false);
        
        for(int i = 0; i < n; i++) {
            in_array[nums[i]] = true; // Track existing elements
            for(int j = 1; j * j <= nums[i]; j++) {
                if(nums[i] % j == 0) {
                    int div = nums[i] / j;
                    freq[j]++;
                    if(div != j) freq[div]++;
                } 
            }
        }

        vector<int> temp(1e5 + 5, 1);
        for(int i = 2; i < (1e5 + 5); i++) {
            if(temp[i] != 0) {
                for(int j = 2 * i; j < (1e5 + 5); j += i) {
                    temp[j] = 0;
                }
            }
        }

        vector<int> primes;
        for(int i = 2; i < (1e5 + 5); i++) {
            if(temp[i] == 1) primes.push_back(i);
        }

        int ans = -1e9;
        
        // 1. Process elements ALREADY in the array
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            vector<int> fac = factor_maker(num, primes);
            int change = f(fac, freq);
            
            int cost = (num == 1) ? 0 : (change - 1);
            ans = max(ans, num - cost);
        }

        // 2. Process all other candidates up to maxVal
        for(int num = 1; num <= maxVal; num++) {
            if(in_array[num]) continue; 
            
            vector<int> fac = factor_maker(num, primes);
            int change = f(fac, freq);
            
            int cost = (change == 0) ? 1 : change;
            ans = max(ans, num - cost);
        }

        return ans;
    }
};