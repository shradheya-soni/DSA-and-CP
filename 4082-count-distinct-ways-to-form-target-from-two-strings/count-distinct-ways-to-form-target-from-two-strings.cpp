class Solution {
public:
    int mod = 1000000000 + 7;
    int dp[102][102][102][2][2];
    int f(int i,int i1,int i2,int c1,int c2,string&s1,string&s2,string&t){
        int n = t.length();
        int n1 = s1.length();
        int n2 = s2.length();

        if(i >= n){
            if(c1 == 0 || c2 == 0) return 0;
            return 1;
        }

      
        if(dp[i][i1][i2][c1][c2] != -1) return dp[i][i1][i2][c1][c2];
        int ans = 0; 
        int fl = 0;
        for(int j = i1;j<n1;j++){
            if(s1[j] == t[i]){
                fl = 1;
                ans = (ans + f(i+1,j+1,i2,1,c2,s1,s2,t))%mod;
                // ans = (ans + f(i,i1+1,i2,c1,c2,s1,s2,t))%mod;

            }
        }
        for(int j = i2;j<n2;j++){
            if(s2[j] == t[i]){
                fl = 2;
                ans = (ans + f(i+1,i1,j+1,c1,1,s1,s2,t))%mod;
                // ans = (ans + f(i,i1+1,i2,c1,c2,s1,s2,t))%mod;

            }
        }
        
        // if(fl == 0 &&( i1<n1 || i2<n2)) ans += f(i,i1+1,i2+1,c1,c2,s1,s2,t);
       


        return dp[i][i1][i2][c1][c2] = ans%mod ;

    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,0,0,word1,word2,target);
    }
};