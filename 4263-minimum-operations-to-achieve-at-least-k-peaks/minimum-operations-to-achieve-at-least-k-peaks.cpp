class Solution {
public:
    // int dp[5001][2505][2];
    int minOperations(vector<int>& arr, int k){
        if(k>arr.size()/2) return -1;

        int n = arr.size();
      
     
        int ans = 1e9;
        for(int s0 = 0;s0<2;s0++){
            for(int sn = 0;sn<2;sn++){
                vector<int> dp1p(k + 6, 1e9);
                vector<int> dp1(k + 6, 1e9);

                vector<int> dp2p(k + 6, 1e9);
                vector<int> dp2(k + 6, 1e9);


                if(s0 == 0){
                  
                    dp1p[0] = 0;
                    
                }
                else{
                    if(sn == 0){
                        dp2p[0] = 0;
                        dp2p[1] = max({0,arr[n-1]-arr[0]+1,arr[1]-arr[0]+1});
                    }
                }
                if(sn == 1 && s0 == 1) continue;
                for(int i = 1;i<arr.size();i++){
                    for(int p = 0;p<=k;p++){
                        if(i == n-1){
                            if(sn == 1 && p>0){
                                dp2[p]  = dp1p[p-1]  + max({0, arr[i-1] - arr[i] + 1,(i+1<n)? arr[i+1] - arr[i] + 1 :arr[0]-arr[i]+1}) ;
                            }
                            else{
                                dp1[p]  = min(dp2p[p] ,dp1p[p]);
                            }
                            continue;
                        }
                        if(p>0) dp2[p]  = dp1p[p-1]  + max({0, arr[i-1] - arr[i] + 1,(i+1<n)? arr[i+1] - arr[i] + 1 :arr[0]-arr[i]+1}) ;
                        dp1[p]  = min(dp2p[p] ,dp1p[p] );
                    }
                    dp1p = dp1;
                    dp2p = dp2;
                }
                if(sn == 1) ans = min({ans,dp2[k]});
                else ans = min({ans,dp1[k]});

            }
        }
        return ans;
    }
};