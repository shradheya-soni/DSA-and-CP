class Solution {
public:
    vector<vector<int>> dp;
    
    int f(int i, int prev_idx, vector<vector<int>>& arr, int lim) {
        int m = arr.size();
        int n = arr[0].size();
        
        if (i >= n) return 0;
       
        if (dp[i][prev_idx + 1] != -1) {
            return dp[i][prev_idx + 1];
        }
        

        int ans = 1 + f(i + 1, prev_idx, arr, lim);
        
        bool valid = true;
        if (prev_idx != -1) {
            for (int j = 0; j < m; j++) {
                if (abs(arr[j][i] - arr[j][prev_idx]) > lim) {
                    valid = false;
                    break;
                }
            }
        }
        
        if (valid) {
            
            ans = min(ans, f(i + 1, i, arr, lim));
        }
        
        return dp[i][prev_idx + 1] = ans;
    }
    
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid[0].size();

        dp.assign(n, vector<int>(n + 1, -1));
        
        return grid[0].size() - f(0, -1, grid, limit);
    }
};