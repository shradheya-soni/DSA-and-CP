class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 1, 0), suf(n + 1, 0);
        for (int k = 0; k < n; ++k) pref[k + 1] = gcd(pref[k], nums[k]); 
        for (int k = n - 1; k >= 0; --k) suf[k] = gcd(suf[k + 1], nums[k]);  

        int total = pref[n], best = 0;
        for (int k = 0; k <= n; ++k) best += pref[k] == suf[k]; 
        auto walk = [&](int k, int cur, int step, int g) {  
            while (cur != g) { cur = gcd(cur, nums[k]); k += step; }
            return k;
        };

        for (int i = 0; i < n; ++i) {
            int g = gcd(pref[i], suf[i + 1]);  
            if (g == total) continue;  
            int l = pref[i] == g ? walk(0, 0, 1, g) : walk(i + 1, pref[i], 1, g);
            int r = suf[i + 1] == g ? walk(n - 1, 0, -1, g) : walk(i - 1, suf[i + 1], -1, g);
            best = max(best, r - l + 2 - (l <= i && i <= r));
        }

        return best;
    }
};