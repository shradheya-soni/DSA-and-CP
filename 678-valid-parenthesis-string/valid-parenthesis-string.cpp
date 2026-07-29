class Solution {
   
    vector<vector<int>> dp;

    bool solve(int i, int openCount, const string& s) {
    
        if (openCount < 0) return false;
        
        if (i == s.length()) return openCount == 0;
        

        if (dp[i][openCount] != -1) return dp[i][openCount];
        
        bool isValid = false;
        
        if (s[i] == '(') {
            isValid = solve(i + 1, openCount + 1, s);
        } 
        else if (s[i] == ')') {
            isValid = solve(i + 1, openCount - 1, s);
        } 
        else {
            isValid = solve(i + 1, openCount + 1, s) || 
                      solve(i + 1, openCount - 1, s) || 
                      solve(i + 1, openCount, s);
        }
        
        return dp[i][openCount] = isValid;
    }

public:
    bool checkValidString(string s) {
        int n = s.length();
       
        dp.assign(n, vector<int>(n, -1));
        return solve(0, 0, s);
    }
};