class Solution {
public:
    static bool cmp(const pair<pair<int,int>,pair<int,int>>& a, const pair<pair<int,int>,pair<int,int>>& b, int block_size) {
        int b1 = a.first.first / block_size;
        int b2 = b.first.first / block_size;
        if(b1 != b2) return b1 < b2; 
        
        // Even/Odd optimization to cut right-pointer movement in half
        if(b1 % 2 == 0) return a.first.second < b.first.second;
        return a.first.second > b.first.second;
    }
    
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int block_size = max(1, (int)sqrt(n));
        
        // 1. Coordinate Compression (Bypasses the unordered_map TLE trap)
        vector<int> sorted_unique = nums;
        sort(sorted_unique.begin(), sorted_unique.end());
        sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());
        
        vector<int> compressed_nums(n);
        for(int i = 0; i < n; i++) {
            // Map the massive 10^9 numbers to safe 0-10^4 indices
            compressed_nums[i] = lower_bound(sorted_unique.begin(), sorted_unique.end(), nums[i]) - sorted_unique.begin();
        }
        
        // 2. Setup Mo's Algorithm
        vector<pair<pair<int,int>,pair<int,int>>> q(queries.size());
        for(int i = 0; i < queries.size(); i++){
            q[i] = {{queries[i][0], queries[i][1]}, {i, queries[i][2]}};
        }
        
        // Pass block_size via lambda for the static comparator
        sort(q.begin(), q.end(), [&](auto& a, auto& b) { return cmp(a, b, block_size); });
        
        // 3. Flat Array for True O(1) Frequency Tracking
        vector<int> freq(sorted_unique.size(), 0);
        set<pair<int,int>> st;
        
        auto add = [&](int comp_idx) {
            int current_f = freq[comp_idx];
            if(current_f > 0) {
                // Direct erase is faster than find() + erase()
                st.erase({current_f, -sorted_unique[comp_idx]}); 
            }
            freq[comp_idx]++;
            st.insert({freq[comp_idx], -sorted_unique[comp_idx]});
        };
        
        auto del = [&](int comp_idx) {
            int current_f = freq[comp_idx];
            st.erase({current_f, -sorted_unique[comp_idx]});
            freq[comp_idx]--;
            if(freq[comp_idx] > 0) {
                st.insert({freq[comp_idx], -sorted_unique[comp_idx]});
            }
        };

        int L = 0, R = -1;
        vector<int> ans(q.size(), 0);
        
        for(auto& it : q){
            int l = it.first.first;
            int r = it.first.second;
            int id = it.second.first;
            int threshold = it.second.second;

            // Expand first, then contract (Safest Mo's order)
            while(R < r) add(compressed_nums[++R]);
            while(L > l) add(compressed_nums[--L]);
            while(L < l) del(compressed_nums[L++]);
            while(R > r) del(compressed_nums[R--]);

            if(st.empty() || st.rbegin()->first < threshold) {
                ans[id] = -1;
            } else {
                ans[id] = -(st.rbegin()->second); 
            }
        }
        
        return ans;
    }
};