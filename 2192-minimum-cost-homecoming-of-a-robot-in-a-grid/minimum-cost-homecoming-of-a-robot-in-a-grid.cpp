class Solution {
public:
    
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int a = startPos[0];
        int b = startPos[1];
        int c = homePos[0];
        int d = homePos[1];
     
        int ans = 0;
        for(int i = min(c+1,a+1);i<=(max(a-1,c-1));i++){
            ans += rowCosts[i];
        }
        for(int i = min(d+1,b+1);i<=(max(d-1,b-1));i++){
            ans += colCosts[i];
        }
        if(a!=c) ans += rowCosts[c];
        if(b != d) ans += colCosts[d];
        return ans;
    }
};