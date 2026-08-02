class Solution {
public:
    vector<int> mpp;
    // int dp[51][51][21][21][51];
    unordered_map<string,int> memo;
    void f(vector<int> &arr,vector<int> &fuel,int d1,int d2,int rem1,int rem2,int i,int maxi){
        if(i == arr.size()){
            mpp[i] = min(maxi,mpp[i]);
            return;
        }
        if(d1 < arr[i] && d2 < arr[i]){
            mpp[i] = min(maxi,mpp[i]);
            return ;
        }
        string state = to_string(i) + "_" + to_string(d1) + "_" + to_string(rem1) + "_" + to_string(rem2);
    
        
        if (memo.find(state) != memo.end() && memo[state] <= maxi) {
            return;
        }
        memo[state] = maxi;
        if(rem1 == 0 && rem2 == 0){
            if(d1 >= arr[i]) f(arr,fuel,d1-arr[i],d2,arr[i],rem2,i+1,maxi);
            if(d2 >= arr[i]) f(arr,fuel,d1,d2-arr[i],rem1,arr[i],i+1,maxi);
        }
        else if(rem1 > 0 && rem2 == 0){
            if(d1>=arr[i]) f(arr,fuel,d1-arr[i],d2,arr[i],rem2,i+1,max(maxi,rem1));
            if(d2 >= arr[i]) f(arr,fuel,d1,d2-arr[i],rem1,arr[i],i+1,maxi);
        }
        else if(rem2 > 0 && rem1 == 0){
            if(d2>=arr[i]) f(arr,fuel,d1,d2-arr[i],rem1,arr[i],i+1,max(maxi,rem2));
            if(d1 >= arr[i]) f(arr,fuel,d1-arr[i],d2,arr[i],rem2,i+1,maxi);
        }
        else{
            if(d1>=arr[i]) f(arr,fuel,d1-arr[i],d2,arr[i],max(0,rem2-rem1),i+1,max(maxi,rem1));
            if(d2>=arr[i]) f(arr,fuel,d1,d2-arr[i],max(rem1-rem2,0),arr[i],i+1,max(maxi,rem2));
        }

        return ;
        
    }
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        mpp.assign(demand.size()+5,1e9);
        // memset(dp,-1,sizeof(dp));

        f(demand,fuel,fuel[0],fuel[1],0,0,0,0);
        int ans = -1;
        for(int i = 0;i<mpp.size();i++){
            if(mpp[i]!=1e9){
                ans = mpp[i];
            }
        }
        if(fuel[0] < demand[0] && fuel[1] < demand[0]) return -1;
        return ans;

    }
}; 