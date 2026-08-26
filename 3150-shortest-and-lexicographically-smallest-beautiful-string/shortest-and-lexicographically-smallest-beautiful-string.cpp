class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        set<string> st;
        int n = s.length();
        int sz = 1e9;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            string str = "";
            for(int j = i;j<n;j++){
                
                str += s[j];
                if(s[j] == '1') cnt++;

                if(cnt == k){
                    st.insert(str);
                    sz = min(sz,(int)str.length());
                    // cout<<i<<" ";
                    break;
                }

                
            }
        }
        if(st.size()==0) return "";
        
        for(auto it : st){
            if(it.length() == sz) return it;
            cout<<it<<" ";
        }
        return "";
    }
};