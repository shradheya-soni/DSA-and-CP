class Solution {
public:
    long long mod = 1e9+7;
    int f(vector<string> &words , string target,int i,int k){
        if(k == target.length()){
            return 1;
        }
        if(i == words[0].length()){
            return 0;
        }
        int cnt = 0;

        for(int j = 0;j<words.size();j++){
            if(words[j][i] == target[k]){
                cnt = (cnt + f(words,target,i+1,k+1))%mod;
            } 
        }
        cnt = (cnt + f(words,target,i+1,k))%mod;
        return cnt;
        
    }

    int numWays(vector<string>& words, string target) {
        // return f(words,target,0,0);
        vector<vector<long long>> dp(words[0].length()+5,vector<long long>(target.length()+5,0));
        for(int i = 0;i<=words[0].length();i++){
            dp[i][target.length()] = 1;
        }
        vector<vector<long long>> freq(1005,(vector<long long>(30,0)));
        for(int i = 0;i<words.size();i++){
            for(int j = 0;j<words[0].length();j++){
                freq[j][words[i][j] - 'a']++;
            }
        } 
        for(int k = target.length()-1;k>=0;k--){
            for(int i = words[0].length()-1;i>=0;i--){

                
                    
                    dp[i][k] = (dp[i][k] + (freq[i][target[k] - 'a']*dp[i+1][k+1]%mod)%mod)%mod;
                     
                
                dp[i][k] = (dp[i][k] + dp[i+1][k])%mod;
            }
        }
        return (int)dp[0][0];
    }
};