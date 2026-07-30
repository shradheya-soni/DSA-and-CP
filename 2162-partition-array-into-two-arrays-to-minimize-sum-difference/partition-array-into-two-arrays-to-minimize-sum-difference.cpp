class Solution {
public:
    void f(vector<int> &arr, int i, int countA, int x, int total, map<int,vector<int>> &mpp) {
        int n = arr.size();
        if (i == n) {
            mpp[countA].push_back(x);
            return ;
        }


        int pick = INT_MAX, not_pick = INT_MAX;
        
        f(arr, i + 1, countA + 1, x + arr[i], total,mpp);
        f(arr, i + 1, countA, x, total,mpp);

        return ;
    }
    int minimumDifference(vector<int>& nums) {
        map<int,vector<int>> mpp1;
        map<int,vector<int>> mpp2;

        int n = nums.size()/2;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0;i<2*n;i++){
            if(i<n) a[i] = nums[i];
            else b[i - n] = nums[i];
        }
        
        int total = accumulate(nums.begin(), nums.end(),0);
        f(a, 0, 0, 0, total,mpp1);
        f(b, 0, 0, 0, total, mpp2);

        for(auto &it : mpp2){
            sort(it.second.begin(),it.second.end());
        }
        int mini  =1e9;
        for(auto it : mpp1){
            int sz = it.first;
            vector<int> v1 = it.second;
            vector<int> v2 = mpp2[n-sz];
            
            for(int i = 0;i<v1.size();i++){
                int need = (total-2*v1[i])/2;
                int ind = lower_bound(v2.begin(),v2.end(),need) - v2.begin();
                if(ind > 0){
                    mini = min(mini,abs(2*(v1[i] + v2[ind-1]) - total));
                }
                if(ind < v2.size())mini = min(mini,abs(2*(v1[i] + v2[ind])- total));
            }
        }
        return mini;
    }
};