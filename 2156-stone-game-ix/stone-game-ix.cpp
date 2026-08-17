class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> f(3,0);
        for(int i = 0;i<stones.size();i++){
            f[stones[i]%3]++;
        }
        if(f[0]%2 == 0){
            return min(f[1],f[2]) >= 1;
        }
        else{
            return (abs(f[1] - f[2])>=3);
        }
        return false;
    }
};