class Solution {
public:
    vector<int> dp;
    int f(int i,vector<int> &arr){
        int n = arr.size();
        if(i == n){
            return 0;
        }
        if(dp[i] != -1000000000) return dp[i];
        int one = -1000000000,two=-1000000000,three=-1000000000;
        one = arr[i] - f(i+1,arr);
        if(i+1<n) two = arr[i]+arr[i+1] - f(i+2,arr);
        if(i+2 < n) three = arr[i]+arr[i+1] +arr[i+2] - f(i+3,arr);

        return dp[i] = max(one,max(two,three));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+1,-1000000000);
        int num = f(0,stoneValue);
        if(num > 0) return "Alice";
        else if(num == 0) return "Tie";
        else return "Bob";
    }
};