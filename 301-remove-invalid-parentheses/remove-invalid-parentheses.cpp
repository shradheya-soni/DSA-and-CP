class Solution {
public:
    vector<string> v;
    vector<vector<int>> dp;
    void f(string &s,int i,int cnt,string &ans){
        if(cnt < 0) return;
        if(i == s.length()){
            if(cnt==0){
                dp[i][cnt] = 1;
                v.push_back(ans);
            }
            return;
        }

        if(dp[i][cnt] != 0){
            return ;
        }

        if(s[i] == '('){
            ans += '(';
            f(s,i+1,cnt+1,ans);
            ans.pop_back();

            f(s,i+1,cnt,ans);
        }
        else if(s[i] == ')'){
            ans += ')';
            f(s,i+1,cnt-1,ans);
            ans.pop_back();

            f(s,i+1,cnt,ans);
        }
        else{
            ans += s[i];
            f(s,i+1,cnt,ans);
            ans.pop_back();
        }
        return ;
    }


    vector<string> removeInvalidParentheses(string s) {
        string ster = "";
        dp.assign(26,vector<int>(26,0));
        f(s,0,0,ster);
        vector<string> ans;
        set<string> st;
        int maxi = 0;
        for(int i = 0;i<v.size();i++) {maxi = max(maxi,(int)v[i].length());}
        for(int i = 0;i<v.size();i++){
            if(v[i].length() == maxi){
                st.insert(v[i]);
            }
        }
        for(auto it : st) ans.push_back(it);
        return ans;
    }

};