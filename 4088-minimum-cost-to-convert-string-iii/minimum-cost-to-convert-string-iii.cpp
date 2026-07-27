class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.length();
        int m = rules.size();
        vector<int> dp(n+5,1e9);
        for(int i = 0;i<n;i++){
            if(source[i] == target[i]){
                if(i>0) dp[i] = min(dp[i],dp[i-1]);
                else dp[i] = 0;
            }
            for(int j = 0;j<m;j++){
                int sz = rules[j][0].size();
                if(i-sz+1 >= 0){
                    int ind = i-sz+1;
                    int flag = 0;
                    int ex = 0;
                    for(int k = 0;k<sz;k++){
                        if((rules[j][0][k] != source[ind] && rules[j][0][k] != '*')|| rules[j][1][k ] != target[ind]){
                            flag = 1;
                            break;
                        }
                        if(rules[j][0][k] == '*')ex++;
                        ind++;
                    }
                    if(flag == 0){
                        int num = 0;
                        if(i-sz >= 0) num = dp[i-sz];
                        dp[i] = min(dp[i],costs[j] + num+ex);
                    }
                }
            }
            

        }
        if(dp[n-1] == 1e9) return -1;
        return dp[n-1];
        
    }
};