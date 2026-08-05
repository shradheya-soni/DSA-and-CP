class Solution {
public:
    
    bool f(vector<long long> &arr,long long mid,long long k,int r){
        int n = arr.size();
        vector<long long> pre(n,0);
        long long rem = 0;
        long long req = 0;
        for(int i = 0;i<n;i++){
            rem += pre[i];

            if(arr[i]+rem < mid){
                long long num = mid - (arr[i]+rem) ;
                rem += num;
                if(i+2*r+1<n) pre[i+2*r+1] -= num;
                req += num;
            }
        }
        return (req <= k);
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> arr(n,0);
        for(int i = 0;i<n;i++){
            arr[max(0,i-r)] += stations[i];
            if(i+r+1 < n) arr[i+r+1] -= stations[i];
        }

        for(int i = 1;i<n;i++) arr[i] += arr[i-1];
        long long l = 0;
        long long j = 1000000000000+10;
        long long ans = 0;
        while(l+1<j){
            long long mid = (l+j)/2ll;
            long long k1 = k;
            if(f(arr,mid,k1,r)){
                ans = mid;
                l = mid;
            }
            else {
                j = mid;

            }
        }
        return ans;
    }
};