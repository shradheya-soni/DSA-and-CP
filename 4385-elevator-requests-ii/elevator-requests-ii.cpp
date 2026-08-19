class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        long long m = requests.size();
        vector<vector<vector<long long>>> dp(m+2,vector<vector<long long>>(m+2,vector<long long>(2,1e18)));
        vector<long long> arr;
        int f = 0;
        for(int i = 0;i<m;i++){
            arr.push_back(requests[i]);
            if(requests[i] == start) f = 1;
        }
        if(f== 0){
            arr.push_back(start);
            m+=1;
        }
        sort(arr.begin(),arr.end());
        int ind = 0;
        for(int i = 0;i<m;i++){
            if(arr[i] == start) {dp[i][i][0] = 1,dp[i][i][1] = 0,ind = i;}
        }

        for(int len = 2;len<=m;len++){
            for(int i = 0;i<=m-len;i++){
                int j = i + len -1;
                long long rem = m-len +1;
                if(i<=ind && ind<=j){

                }
                else rem--;

                dp[i][j][0] = min({dp[i][j][0],dp[i+1][j][0] + (arr[i+1]-arr[i])*rem,dp[i+1][j][1] + (arr[j]-arr[i])*rem});
                dp[i][j][1] = min({dp[i][j][1],dp[i][j-1][0] + (arr[j]-arr[i])*rem,dp[i][j-1][1] + (arr[j]-arr[j-1])*rem});


            }
        }
        return min(dp[0][m-1][0],dp[0][m-1][1]);
    }
};