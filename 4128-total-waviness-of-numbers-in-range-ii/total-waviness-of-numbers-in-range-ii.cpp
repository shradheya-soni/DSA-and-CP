class Solution {
public:
    
    pair<long long,long long> dp[2][2][11][11][20][2];
    long long visited[2][2][11][11][20][2];


    pair<long long,long long> f(int tightl,int tightr,int prev,int pp,int i,string &s1,string &s2,int lz){
        if(i == s1.length()){
            return {1ll,0ll};
        }
        if(visited[tightl][tightr][prev][pp][i][lz] != 0){
            return dp[tightl][tightr][prev][pp][i][lz];
        }
        int lb = 0;
        int ub = 9;
        pair<long long,long long> ans = {0,0};
        if(tightl) lb = s1[i]-'0';
        if(tightr) ub = s2[i]-'0';
        for(int k = lb;k<=ub;k++){
            int next_lz = lz&&(k==0);

            int next_prev = next_lz ? 10 : k;
            int next_pp = next_lz ? 10 : prev;
            
            auto it = f(tightl & (k == lb), tightr & (k == ub), next_prev, next_pp, i + 1, s1, s2, next_lz);
            
            ans.second += it.second;
            ans.first += it.first;


            if (!next_lz && prev != 10 && pp != 10){
                if(prev > pp&& (k<prev)){
                    ans.second += it.first;
                }
                else if (prev < pp && (k>prev)){
                    ans.second += it.first;

                }
            }
            
        }
        visited[tightl][tightr][prev][pp][i][lz] = 1;
        return dp[tightl][tightr][prev][pp][i][lz] = ans;
    }
    long long totalWaviness(long long num1, long long num2){
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        s1 = string(s2.length() - s1.size(), '0') + s1;
        memset(visited,0,sizeof(visited));
        memset(dp,0,sizeof(dp));

        return f(1,1,10,10,0,s1,s2,1).second;

    }
};