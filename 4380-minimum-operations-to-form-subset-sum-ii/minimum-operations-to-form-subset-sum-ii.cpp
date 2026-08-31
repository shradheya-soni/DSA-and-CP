#include <vector>
#include <queue>
#include <cstring> // For memset

using namespace std;

class Solution {
public:
    int dp[105][5005];
    vector<pair<int, int>> reachable[105]; 
    
    int f(int i, int sum, vector<int>& nums) {
        if (sum == 0) return 0;
        if (i == nums.size()) return 1e9;

        if (dp[i][sum] != -1) return dp[i][sum];

        int ans = f(i + 1, sum, nums); 
        
        for (auto& it : reachable[i]) {
            int val = it.first;
            int cost = it.second;
            
            if (sum - val >= 0) {
                ans = min(ans, cost + f(i + 1, sum - val, nums));
            }
        }

        return dp[i][sum] = ans;
    }
    
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        
        memset(dp, -1, sizeof(dp));
     
        for (int i = 0; i < n; i++) {
            reachable[i].clear();
            queue<pair<int, int>> q;
            
           
            bool vis[5002] = {false}; 
            
            q.push({nums[i], 0});
            vis[nums[i]] = true;

            while(!q.empty()){
                auto it = q.front();
                q.pop();
                
                int val = it.first;
                int cost = it.second;

                if (val > 0 && val <= sum) {
                    reachable[i].push_back({val, cost});
                }

                if (val * 2 <= sum && !vis[val * 2]) {
                    vis[val * 2] = true;
                    q.push({val * 2, cost + 1});
                }
                
                if (val / 2 > 0 && !vis[val / 2]) {
                    vis[val / 2] = true;
                    q.push({val / 2, cost + 1});
                }
            }
        }

        int ans = f(0, sum, nums);
        return ans >= 1e9 ? -1 : ans;
    }
};