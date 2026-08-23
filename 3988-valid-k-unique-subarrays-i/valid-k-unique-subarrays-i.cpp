struct mo{
    int n = 1e6+5;
    vector<int> freq;
    int dis ;
    int odd ;
    mo(){
        freq.assign(n,0);
        dis = 0;
        odd = 0;
    }
    void add(int ind,const vector<int> &arr){
        int val= arr[ind];
        if(freq[val] == 0){
            dis ++;
        }
        freq[val]++;
        if(freq[val]%2 == 0) odd--;
        else odd++;
        
    }
    void remove(int ind,const vector<int>&arr){
        int val = arr[ind];
        freq[val] --;
        if(freq[val] == 0) dis --;
        if(freq[val] %2 == 0) odd--;
        else odd ++;
    }
};

struct node{
    int l,r,id;
    node(int a,int b,int c){
        l = a;
        r = b;
        id = c;
    }
};
int block ;
    bool cmp(node a, node b){
        int b_a = a.l/block;
        int b_b = b.l/block;
        if(b_a != b_b){
            return b_a < b_b;
        }
        if(b_a%2 == 1){
            return a.r < b.r;
        }
        else return a.r > b.r;
    }
class Solution {
public:
    
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        mo mos;
        int n = nums.size();
        block = sqrt(n);

        vector<node> que;
        for(int i = 0;i<queries.size();i++){
            que.push_back(node(queries[i][0],queries[i][1],i));
        }
        sort(que.begin(),que.end(),cmp);
        vector<bool> ans(queries.size());
        int L = 0;
        int R = -1;
        for(int i = 0;i<que.size();i++){
            int l = que[i].l;
            int r = que[i].r;
            int id = que[i].id;
            
            while(L > l) mos.add(--L,nums);
            while(R < r) mos.add(++R,nums);
            
            while(L < l) mos.remove(L++,nums);
            while(R > r) mos.remove(R--,nums);
            

            if(mos.dis == k && mos.odd == 0){
                ans[id] = true;
            }
            else ans[id] = false;
        }
        return ans;
    }
};