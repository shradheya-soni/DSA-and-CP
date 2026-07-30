class Solution {
public:
int mod = 1e9+7;
    long long limit = 1e9;
    long long power(int n,int e){
        long long num = n;
        long long res = 1;
        while(e>0){
            if(e%2 == 0){
                e/=2;
                num = (num*num)%mod;
            }
            else{
                res = (res*num)%mod;
                e--;
            }
        }
        return res%mod;
    }
    long long C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > limit) return limit;
        }

        return ans;
    }
    long long countPerm(map<char,int> &freq) {
        int rem = 0;
        for (auto &x : freq)
            rem += x.second;

        long long ans = 1;

        int used = 0;
        for (auto &x : freq) {
            ans *= C(used + x.second, x.second);
            if (ans > limit) return limit;
            used += x.second;
        }

        return min(ans, limit);
    }

    string func(string s, int k) {
        string mid= "";
        map<char,int> mpp;
        for(auto it : s) mpp[it]++;
        long long num = 0;
        for(auto it = mpp.begin();it!=mpp.end();it++){
            if(mpp[it->first]%2 == 1) mpp[it->first]--,mid = it->first;
            mpp[it->first]/=2;
            num += mpp[it->first];
        }
        int total = countPerm(mpp);
        if(total < k) return "";
        string ans = "";
        for(int  i = 0;i<s.size()/2;i++){
            int cnt = 0;

            for(int j = 0;j<26;j++){
                long long temp = 0;
             
                char c = 'a'+j;
                if(mpp.find(c) == mpp.end()) continue;
                if(mpp[c] == 0) continue;
                mpp[c] --;
                temp = countPerm(mpp);
                mpp[c]++;
                if(temp  < k){
                    // cnt += temp;
                    k-=temp;
                }
                else{
                    ans += c;
                    mpp[c]--;
                    if(mpp[c] == 0) mpp.erase(c);
                    break;
                }
            }
        }
        string rev = ans;
        reverse(rev.begin(),rev.end());
       
        return (ans+mid+rev);


    }
    string smallestPalindrome(string s) {
        return func(s,1);
    }
};