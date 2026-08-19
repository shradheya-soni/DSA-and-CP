class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        for(int i = 0;i<(1<<n);i++){
            int amt = 0;
            string s = "";
            for(int j = 0;j<n;j++){
                s += to_string((i&(1<<j)) != 0 );
                if(i&(1<<j)){
                    amt += j;
                }
                if(j>0 && (i&(1<<j) && (i&(1<<(j-1))))){
                    amt = 1e9;
                    break;
                } 
            }
            if(amt <= k) {
                // reverse(s.begin(),s.end());
                ans.push_back(s);
            }
        }
        return ans;
    }
};