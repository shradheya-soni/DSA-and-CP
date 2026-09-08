class Solution {
public:
    int mod  = 1e9+7;
    int countArrays(vector<int>& dig) {
        vector<vector<int>> arr(35,vector<int>());
        for(int i = 0 ;i<=5000;i++){
            string s = to_string(i);
            int c = 0;
            for(int j = 0;j<s.length();j++){
                c += (s[j]-'0');
            }
            arr[c].push_back(i);
        }

        int n = dig.size();
        vector<vector<long long>> dp(n+1,vector<long long>(5001,0));
        int d= dig[0];
        if(d<35){    
            for(int j = 0;j<arr[d].size();j++){
                dp[0][arr[d][j]] = 1;
            }
        }
        
        for(int i = 1;i<n;i++){
            int d = dig[i];
            if(d >= 35) continue;
            vector<long long> pre(5001,0);
            pre[0] = dp[i-1][0];
            for(int j = 1;j<=5000;j++){
                pre[j] = (pre[j-1] + dp[i-1][j])%mod;
            }
            for(int j = 0;j<arr[d].size();j++){
                int curr = arr[d][j];
                
                dp[i][curr] = (dp[i][curr] + pre[curr])%mod;
                
            }
            // for(int j =0;j<=5000;j++){
            //     if(dp[i][j] == 0){
            //         dp[i][j] = dp[i-1][j];
            //     }
            // }
        }
        long long ans = 0;
        for(int j = 0;j<=5000;j++){
            ans = (ans + dp[n-1][j])%mod ;
        }
        return ans;
    }
};