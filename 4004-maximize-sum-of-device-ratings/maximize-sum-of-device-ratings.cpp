class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long n = units.size();
        long long m = units[0].size();
        vector<long long> minis(n,0);
        vector<long long> sminis(n,0);
        for(int i = 0;i<units.size();i++){
            long long m1 = 1e9;
            long long m2 = 1e9;
            for(int j = 0;j<m;j++){
                if(units[i][j] < m1){
                    m2 = m1;
                    m1 = units[i][j];
                }
                else if(units[i][j] < m2){
                    m2 = units[i][j];
                }
            }
            minis[i] = m1;
            sminis[i] = m2;


        }
        

        long long ans = 0;{
            for(int i = 0;i<n;i++){
                if(sminis[i] == 1e9){
                    ans += minis[i];
                    minis[i] = 1e9;
                }
                else ans += sminis[i];
            }
        }
        sort(minis.begin(),minis.end());
        sort(sminis.begin(),sminis.end());

        for(int i = 0;i<n;i++){
            if(minis[i] != 1e9){
                ans -= sminis[i] - minis[i];
                break;
            }
        }
        return ans;

    }
};