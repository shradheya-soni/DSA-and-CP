class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            long long sum = 0;
            for(int j = i;j<nums.size();j++){
                sum += nums[j];
                long long n = sum;
                long long len = 0;
                long long las = 1;
                while(n>0){
                    len = n%10;
                    n/=10;

                }
                las/=10;
                if(sum%10 == x && len == x) cnt++;

            }
        }
        return cnt;
    }
};