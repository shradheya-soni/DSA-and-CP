class Solution {
public:
    long long check(vector<int> &arr,long long num){
        int n = arr.size();
        long long cnt = 0;
        for(int i = 1;i<(1<<n);i++){
            int bits = __builtin_popcount(i);
            long long temp = 1;
            for(int j = 0;j<n;j++){
                if(i&(1<<j)){
                    temp = lcm(temp,(long long)arr[j]); 
                }
            }

            if(bits%2 == 1){
                cnt += (num/temp);
            }
            else cnt -= (num/temp);
        }
        return cnt;
    }
    long long f(int k,int num,vector<int>& arr){
        long long l = 0;
        long long r = k+5;
        long long ans = 0;
        while(l+1<r){
            long long mid = l + (r-l)/2;
            long long temp = check(arr,mid*(long long)num);
            if(temp == k){
                return mid*(long long)num;
            }
            if(temp >= k){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return -1;

    }
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(),coins.end(),greater<int>());
        int n = coins.size();
        for(int i = 0;i<n;i++){
            vector<int> arr;
            for(int j =i+1;j<n;j++){
                arr.push_back(coins[j]);
            }
            long long ans = f(k,coins[i],coins);
            if(ans != -1) return ans;
        }

        return -2432343;
    }
};