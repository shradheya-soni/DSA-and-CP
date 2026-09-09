class Solution {
public:
    // 2 - neutral, 0 - inc, 1 - dec
    long long dp[20][2][4][164][11];
    bool check(int sum){
        string s = to_string(sum);
        int asc = 1;
        for(int i =1;i<s.length();i++){
            if(s[i]<=s[i-1]){
                asc = 0;
                break;
            }
        }
        int dec = 1;
        for(int i =1;i<s.length();i++){
            if(s[i]>=s[i-1]){
                dec = 0;
                break;
            }
        }
        return (asc||dec);
    }
    long long f(int i,int tl,int tr,int lz,string &s1,string &s2,int parity,int sum,int prev){
        if(i == s1.length()){
            if(parity != 2) return 1LL;
            
            else{
                string s = to_string(sum);
                if(check(sum)) return 1LL;
                // cout<<sum<<" ";
                return 0;
            }   
        }
        if(dp[i][lz][parity][sum][prev] != -1 && tl == 0 && tr == 0) return dp[i][lz][parity][sum][prev];
        int lb = (tl==1)?(s1[i]-'0'):0;
        int rb = (tr==1)?(s2[i]-'0'):9;
        long long ans = 0;
        for(int k = lb; k<=rb ;k++){
            if(prev == 10){
                if(k == 0){
                    ans += f(i+1,tl&(k==lb),tr&(k==rb),lz&(k==0),s1,s2,3,sum,10);
                }
                else{
                    ans += f(i+1,tl&(k==lb),tr&(k==rb),lz&(k==0),s1,s2,3,sum+k,k);
                }
                continue;
            }
            if(k > prev){
                if(parity == 0 || parity == 3) ans += f(i+1,tl&(k==lb),tr&(k==rb),lz&(k==0),s1,s2,0,sum+k,k);
                else ans += f(i+1,tl&(k==lb),tr&(k==rb),lz&(k==0),s1,s2,2,sum+k,k);
            }
            else if(k < prev){
                if(parity == 1 || parity == 3) ans += f(i+1,tl&(k==lb),tr&(k==rb),lz&(k==0),s1,s2,1,sum+k,k);
                else ans += f(i+1,tl&(k==lb),tr&(k==rb),lz&(k==0),s1,s2,2,sum+k,k);
            }
            else{
                ans += f(i+1,tl&(k==lb),tr&(k==rb),lz&(k==0),s1,s2,2,sum+k,k);
            }
        }
        if (tl == 0 && tr == 0) dp[i][lz][parity][sum][prev] = ans;
        return ans;


    }
    long long countFancy(long long l, long long r) {
        string temp = to_string(l);
        string s2 = to_string(r);
        string s1 = "";
        for(int i = 0;i<s2.length()-temp.length();i++){
            s1 += '0';
        }
        s1 += temp;
        memset(dp,-1,sizeof(dp));
        long long ans = 0;
        return f(0,1,1,1,s1,s2,3,0,10);
        

    }
};