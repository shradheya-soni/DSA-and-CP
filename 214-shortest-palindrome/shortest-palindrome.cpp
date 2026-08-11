class Solution {
public:
    string f(string &s,string &ori){
        int n = s.length();
        vector<int> p(n+1,0);

        int l = 0;
        int r = 0;
        for(int i = 0;i<n;i++){
            if(r+l-i >= 0 && r+l-i < n) p[i] = max(0,min(r-i,p[r+l-i]));
            while(i-p[i]>=0 && i+p[i] <n &&  s[i+p[i]] == s[i-p[i]]){
                p[i]++;
            }
            if(i+p[i] > r){
                r = i+ p[i];
                l = i -p[i];
            }

        }
        int ind = 0;
        int fl = 0;
        int maxi = 0;
        for(int i = 0;i<n;i++){
            if(i-p[i] == -1){
                if(s[i] == '#'){
                    ind = (i)/2;
                    maxi = ori.length() - ind;
                    fl = 0;
                }
                else {
                    ind = i/2;
                    maxi = ori.length() - ind;
                    fl = 1;
                }
            }
        }
        string ans = "";
        if(fl == 1){
            ans += ori[ind];
            ind++;
        }

        string temp = ori.substr(ind,maxi-fl);
        ans = ans + temp;
        reverse(temp.begin(),temp.end());
        ans = temp + ans;

        // ans= temp2 + ans + temp;
        return ans;

    }
    string shortestPalindrome(string s) {
        string str = "";
        for(int i = 0;i<s.length();i++){
            str += '#' ;
            str += s[i];
        }
        str += '#';

        
        return f(str,s);
    }
};