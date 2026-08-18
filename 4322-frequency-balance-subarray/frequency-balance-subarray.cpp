class Solution {
public:
    int getLength(vector<int>& nums) {
        map<int,int> mpp;
        map<int,int> freq;
        int ans =0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(freq.find(mpp[nums[j]]) != freq.end()){
                    freq[mpp[nums[j]]]--;
                    if(freq[mpp[nums[j]]] == 0){
                        freq.erase(mpp[nums[j]]);
                    }
                }
                mpp[nums[j]]++;
                freq[mpp[nums[j]]]++;
                if(freq.size() <= 2){
                    if(freq.size() == 1){
                        if(mpp.size() == 1){
                            ans = max(ans,j-i+1);
                        }
                    }
                    else if(freq.begin()->first *2 == prev(freq.end())->first){
                        ans = max(ans,j-i+1);
                    }
                }
            }
            mpp.clear();
            freq.clear();
        }

        return ans;
    }
};