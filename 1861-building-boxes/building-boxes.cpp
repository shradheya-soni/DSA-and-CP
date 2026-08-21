class Solution {
public:
    int minimumBoxes(int n) {
        int m = 2000;
        if(n <= 3) return n;
        vector<vector<long long>> arr(2,vector<long long>(m,0));
        arr[0][0] = 4;
        arr[1][0] = 3;
        long long inc = 3;
        for(long long i = 1;i<m;i++){
            arr[1][i] = arr[1][i-1] + inc;
            inc ++;
        }

        for(long long i = 0;i<m-1;i++){
            arr[0][i+1] = arr[0][i] + arr[1][i+1];
        }
        long long ans = 0;
   
            long long ind = upper_bound(arr[0].begin(),arr[0].end(),n) - arr[0].begin() -1 ;
            if(ind == -1){
                ans += n;
                n = 0;
            }
            else{
                ans += arr[1][ind];
                n -= arr[0][ind];
            }
          ind = lower_bound(arr[1].begin(),arr[1].end(),n) - arr[1].begin() ;
        if(n <= 2 && n > 0) ans += n;
        else if(n > 2) ans += ind + 2;

        return (int)ans;
    }
};