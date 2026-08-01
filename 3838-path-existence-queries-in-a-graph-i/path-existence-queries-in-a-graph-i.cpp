class dsu{
public :
    
    vector<int> parent,size;
    dsu(int n){
        parent.assign(n,0);
        size.assign(n,1);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }
    int find_par(int val){
        if(parent[val] == val) return val;
        else return find_par(parent[val]);
    }
    void order_by_size(int a,int b){
        int pa = find_par(a);
        int pb = find_par(b);

        if(pa == pb) return;
        else if(size[pa] > size[pb]){
            size[pa] += size[pb];
            parent[pb] = pa;
        }
        else{
            size[pb] += size[pa];
            parent[pa] = pb;
        }

    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        dsu d(n);
        for(int i = 0;i<n-1;i++){
            if(abs(nums[i] - nums[i+1]) <= maxDiff){
                d.order_by_size(i,i+1);
            }
        }
        vector<bool> ans;
        for(auto it : queries){
            if(d.find_par(it[0]) == d.find_par(it[1])){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;

    }
};