class Solution {
public:

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<pair<int,int>> arr(n);
        for(int i = 0;i<n;i++){
            arr[i] = {items[i][1],items[i][0]};
        }
        sort(arr.begin(),arr.end());

        vector<int> cnt(n+1,0);
        for(int i = 0;i<n;i++) cnt[arr[i].second]++;

        vector<long long> mul(n+1,0);
        for(int i = 1;i<n;i++){
            for(int j = i;j<n;j+=i){
                mul[i] += cnt[j];
            }
        }
        
        vector<int> buy(n+1,0);
        for(int i = 0;i<n;i++){
            buy[i] = mul[arr[i].second]-1;
        }
   
        long long ans = 0;
        vector<pair<long long,long long>> fin;
        int mini = arr[0].first;
        // price,kitne le skte h
        for(int i = 0;i<n;i++){
            int p = arr[i].first;
            int q = buy[i];
            if(q > 0 && p < 2LL*mini){
                fin.push_back({p,q});
            }
        }
        sort(fin.begin(),fin.end());
        for(auto it : fin){
            long long temp = min(it.second,budget/it.first);
            ans += temp*2LL;
            budget -= temp*it.first;
        }
        ans += budget/mini;
        return ans;
    }
};