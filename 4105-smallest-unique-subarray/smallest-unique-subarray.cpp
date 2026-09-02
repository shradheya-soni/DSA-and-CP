class Solution {
public:
    int p1 = 100019,p2 = 100043;
    int m1 = 1e9+7,m2 = 1e9+9;
    vector<long long> pow_p1,pow_p2;
    vector<long long> hash1,hash2;
    void gen(vector<int>&nums){
        int n = nums.size();
        hash1[0] = nums[0];
        hash2[0] = nums[0];
        for(int i = 1; i <= n; i++){
            pow_p1[i] = (pow_p1[i-1]*p1)%m1;
            pow_p2[i] = (pow_p2[i-1]*p2)%m2;
        }
        for(int i = 1;i<n;i++){
            hash1[i] = (hash1[i-1]*p1 + nums[i])%m1;
            hash2[i] = (hash2[i-1]*p2 + nums[i])%m2;
        }
    }

    pair<long long,long long> get_hash(int l,int r){
        
        long long h1 = (hash1[r] - (((l>0)?hash1[l-1]:0)*pow_p1[r-l+1])%m1)%m1;
        long long h2 = (hash2[r] - (((l>0)?hash2[l-1]:0)*pow_p2[r-l+1])%m2)%m2;

        if(h1 < 0) h1 += m1;
        if(h2 < 0) h2 += m2;

        return {h1,h2};
    }

    bool check(vector<int>&nums,int k){
        int l = 0;
        int r = k-1;
        int n = nums.size();
        map<pair<long long,long long>,int> mpp;
        while(r<n){
            auto h = get_hash(l,r);
            mpp[h]++;
            r++;
            l++;
        }
        for(auto it : mpp){
            if(it.second == 1) return true;
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        pow_p1.assign(n+5,1);
        pow_p2.assign(n+5,1);
        hash1.assign(n+5,0);
        hash2.assign(n+5,0);
        gen(nums);

        int l = 0;
        int r = n;
        int ans = n;
        while(l+1<r){
            int mid = l + (r-l)/2;
            if(check(nums,mid)){
                r = mid;
                ans = mid;
            }
            else l = mid;
        }
        return ans;
    }
};