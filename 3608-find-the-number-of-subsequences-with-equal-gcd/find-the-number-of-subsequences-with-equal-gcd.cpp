class Solution {
public:
    int mod = 1e9+7;
    

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        int maxi = *max_element(nums.begin(),nums.end());
        vector<vector<long long>> prev(maxi+1,vector<long long>(maxi+1,0));
        vector<vector<long long>> next(maxi+1,vector<long long>(maxi+1,0));

        
            for(int j = 1;j<=maxi;j++){
                next[j][j] = 1;
            }
        
        for(int i = n-1;i>=0;i--){
            for(int gcd1 = 0;gcd1<=maxi;gcd1++){
                for(int gcd2 = 0;gcd2<=maxi;gcd2++){
                    prev[gcd1][gcd2] = (prev[gcd1][gcd2] + next[gcd(gcd1,arr[i])][gcd2] )%mod;
                    prev[gcd1][gcd2] = (prev[gcd1][gcd2] + next[gcd1][gcd(gcd2,arr[i])])%mod ;
                    prev[gcd1][gcd2] = (prev[gcd1][gcd2] + next[gcd1][gcd2])%mod;

                }
            }
            next = prev;
            prev.assign(maxi+1,vector<long long>(200+5,0));
        }
        int ans= 0;
        
        ans = (ans + next[0][0])%mod;
        
        
        return ans;
    }   
    
};