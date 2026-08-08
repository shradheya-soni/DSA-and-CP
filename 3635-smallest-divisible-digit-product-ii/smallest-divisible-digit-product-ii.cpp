using ll = long long ;
class Solution {
public:
    string func(ll req,int m){
        string s = "";
        for(int i = 9;i>=2;i--){
            while(req%i == 0){
                req/=i;
                s.push_back(i + '0');
            }
        }

        while(s.length()<m){
            s.push_back('1');
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string smallestNumber(string num, long long t) {
        string s = num;
        int n = s.length();
        ll temp = t;
        for(int prime : {2,3,5,7}){
            while(temp%prime == 0){
                temp/=prime;
            }
        }
        if(temp != 1) return "-1";

        vector<ll> rem(n+1,t);
        for(int i = 0;i<n;i++){
            int digit = s[i]-'0';
            if(digit == 0) break;
            rem[i+1] = rem[i]/gcd(rem[i],(ll)digit);
        }
        int ind = s.find('0');
        int idx = n-1;
        if(ind == -1 && rem[n] == 1) return s;
        if(ind != -1) idx = ind;


        for(int i = idx;i>=0;i--){
            int m = n-i-1;
            ll req = rem[i];
            for(int j=max(1,s[i]-'0'+1) ;j<=9;j++){
                ll nreq = rem[i]/gcd(rem[i],(ll)(j));

                string s2 = func(nreq,m);
                if(s2.length() == m){
                    return num.substr(0,i) + (to_string (j)) +s2;
                }
            }
        }
        return func(t,n+1);
    }
};