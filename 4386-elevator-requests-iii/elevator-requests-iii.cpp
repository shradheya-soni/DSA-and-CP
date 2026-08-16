#define ll long long
class Solution {
public:

    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        ll m = requests.size();

        vector<vector<ll>> dp((1<<m)+5,vector<ll>(m,1e18));
        for(ll i = 0;i<m;i++) dp[0][i] = 0ll;
      
        for (ll i = 0; i < m; i++) {
            long long travel_time = abs(start - requests[i][1]);
            dp[1 << i][i] = max((long long)requests[i][0], travel_time);
        }

        for(ll mask = 0;mask<=(1<<(m))-1;mask++){
            for(ll i = 0;i<m;i++)if(mask&(1<<i)){
                ll new_mask = mask^(1<<i);
                for(ll j = 0;j<m;j++)if((new_mask&(1<<j))){
                    ll temp_mask = new_mask^(1<<j);
                    dp[mask][i] = min(dp[mask][i],max((ll)requests[i][0] ,abs((ll)requests[i][1]-(ll)requests[j][1]) + dp[new_mask][j]));
                }
            }
        }

        ll ans = 1e18;

        for(ll i = 0;i<m;i++){
            ans = min(ans,dp[(1<<(m))-1][i]);
        }
        return ans;
    }
};