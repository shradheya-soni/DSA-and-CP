// class dsu{
// public :
    
//     // vector<int> parent,size;
//     dsu(int n){
//         parent.assign(n,0);
//         size.assign(n,1);
//         for(int i = 0;i<n;i++){
//             parent[i] = i;
//         }
//     }
//     int find_par(int val){
//         if(parent[val] == val) return val;
//         else return find_par(parent[val]);
//     }
//     void order_by_size(int a,int b){
//         int pa = find_par(a);
//         int pb = find_par(b);

//         if(pa == pb) return;
//         else if(size[pa] > size[pb]){
//             size[pa] += size[pb];
//             parent[pb] = pa;
//         }
//         else{
//             size[pb] += size[pa];
//             parent[pa] = pb;
//         }

//     }
// };
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> temp(n);
        
        for(int i= 0;i<n;i++){
            temp[i] = {nums[i],i};
        }
        sort(temp.begin(),temp.end());

        vector<int> idx(n,0);
        vector<int> arr(n,0);
        for(int i = 0;i<n;i++){
            idx[temp[i].second] = i;
            arr[i] = temp[i].first;
        }
        vector<vector<int>> parent(n,vector<int>(20,-1));
        for(int i = 0;i<n;i++){
            int curr = arr[i];
            int ind = upper_bound(arr.begin(),arr.end(),curr+maxDiff) - arr.begin()-1;
            parent[i][0] = ind;
        }

        for(int i = 1;i<=18;i++){
            for(int j = 0;j<n;j++){
                if(parent[j][i-1] != -1){   
                    parent[j][i] =  parent[parent[j][i-1]][i-1];


                }
            }
        }
        vector<int> ans;
        for(auto it : queries){
            int na = it[0];
            int nb = it[1];

            int a = idx[na];
            int b = idx[nb];
            if(a>b) swap(a,b);
            int cnt= 0;
            int f = 0;
            // if(a==b )ans.push_back(0);
            for(int i = 18;i>=0;i--){
                if(parent[a][i] == -1) continue;
                // if(parent[a][i] == b){
                //     if(a!=b) cnt += i;
                //     ans.push_back(cnt);
                //     f = 1;
                //     break;
                // }
                if(parent[a][i] < b){
                    cnt += (1<<i);
                    a = parent[a][i];
                }

            }
            if(a == b) ans.push_back(cnt);
            else if(parent[a][0] >= b) ans.push_back(cnt+1);
            else ans.push_back(-1);
        }
        return ans;
    }
};