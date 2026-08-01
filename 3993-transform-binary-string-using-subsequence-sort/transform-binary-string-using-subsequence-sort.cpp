class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int ones = 0;
        int zeros = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '1') ones ++;
            if(s[i] == '0') zeros ++;

        }
        vector<bool> ans;
        for(int i = 0;i<strs.size();i++){
            string s1 = strs[i];
            int o = ones;
            int z = zeros;
            for(int j = 0;j<s1.length();j++){
                if(s1[j] == '0') z--;
                if(s1[j] == '1') o--;

            }
            for(int j = 0;j<s1.length();j++){
                if(s1[j] == '?'){
                    if(z > 0) s1[j] = '0',z--;
                    else s1[j] = '1',o--;
                }
            }
            int f = 1;
            if(o!=0 || z!= 0) f=0;
            int cnt = 0;
            for(int j = 0;j<s1.length();j++){
                if(s1[j] == '0' && s[j] == '1') cnt++;
                if(s1[j] == '1' && s[j] == '0') {
                    cnt--;
                    if(cnt < 0){
                        f= 0;
                        break;
                    }
                }
                
            }

            ans.push_back(f == 1);

        }
        return ans;
    }
};