class Solution {
public:
    int mod= 1e9+7;
    long long power(long long num,long long e){
        long long res = 1;
        long long n = num%mod;
        while(e >= 1){
            if(e%2 == 0){
                e/= 2;
                n =( n*n)%mod;
            }
            else{
                e--;
                res = (res*n)%mod;
            }
        }
        return res%mod;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            long long w = nums[i]%10LL;
            long long d = nums[i]/10LL;

            // cout<<d<<" "<<w<<" ";
            string s = to_string(d);
            string s1 = s.substr(0,w);
            string s2 = s.substr(w);
            long long n1 = s1.empty() ? 1 : stoll(s1);
            long long n2 = s2.empty() ? 1 : stoll(s2);
            cout<<n1<<" "<<n2;
            ans = (ans + power(n1,n2))%mod;

        }
        return ans;
    }

};