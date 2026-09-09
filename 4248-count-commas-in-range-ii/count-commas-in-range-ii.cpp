class Solution {
public:
    long long countCommas(long long n) {
        string s = to_string(n);
        long long cnt = 9000;
        long long ans = 0;
        if(s.length() < 4) return 0;
        for(int i = 4;i<s.length();i++){
            ans += cnt*((i-1)/3);
            cnt *= 10;
        }
        
        long long num = 1;
        for(int i = 1;i<s.length();i++){
            num *= 10;
        }
        num = n-num+1;
        ans += (num)*(((int)s.length() - 1)/3);

        return ans;

    }
};