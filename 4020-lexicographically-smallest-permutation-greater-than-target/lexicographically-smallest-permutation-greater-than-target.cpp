class Solution {
public:
    string ans = "";
    bool f(int i,vector<int>&freq,string &tar,string str,int tight){
        int n = tar.size();
        if(i == n){
            if(tight == 0) ans=str;
            return !tight;
        }
        int v = tar[i]-'a';
        if(tight == 0){
            for(int c = 0;c<=25;c++){
                if(freq[c] != 0){
                    freq[c] --;
                    str += (c+'a');
                    f(i+1,freq,tar,str,tight&(c<=v));
                    freq[c] ++;
                    str.pop_back();
                    return true;
                }
            }
        }
        else{
            for(int c = v;c<=25;c++){
                if(freq[c] != 0){
                    freq[c] --;
                    str += (c+'a');
                    bool fl = f(i+1,freq,tar,str,tight&(c<=v));
                    freq[c] ++;
                    str.pop_back();
                    if(fl == 1) return true;
                }
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(27,0);
        for(int i = 0;i<n;i++){
            freq[s[i]-'a']++;
        }
        f(0,freq,target,"",1);
        if(ans.length() == target.length()) return ans;
        return "";
    }
};