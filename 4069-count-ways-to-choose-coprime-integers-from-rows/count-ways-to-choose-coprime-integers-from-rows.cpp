class Solution {
public:
    int mod = 1e9 + 7;
    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> up(200,0);
        vector<int> down(200,0);
        up[0] = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int k = 0;k<up.size();k++){
                    int g = gcd(mat[i][j],k);
                    down[g] = (down[g] + up[k])%mod;
                }
            }
            up = down;
            down.assign(200,0);
        }
        return up[1]%mod;

    }
};