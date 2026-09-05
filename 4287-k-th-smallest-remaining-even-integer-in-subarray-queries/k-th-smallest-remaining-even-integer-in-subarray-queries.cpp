#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;


template <class T>
using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int block;
struct mo{
    ordered_set<int> st;

    void add(int x){
        if(x%2 == 0) st.insert(x/2);
    }
    void del(int x){   
        if(x%2 == 1) return; 
        st.erase(x/2);
    }

    int check(int mid){
        return st.order_of_key(mid+1);
    }

    int show(int k){
        int l = 0;
        int r = 1e9+100005;
        while(l+1<r){
            int mid = (l+r)/2;
            int c = check(mid);
            
            if(mid-c >= k){
                r = mid;
            }
            else l = mid;
        }
        return r;
    }
};

bool cus(vector<int>& a,vector<int>& b){
    int ba = a[0]/block;
    int bb = b[0]/block;

    if(ba != bb) return ba<bb;
    else if(ba%2 == 0) return a[1] < b[1];
    return b[1]<a[1];
}

class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& arr, vector<vector<int>>& queries) {
        block = sqrt(arr.size());
        int L = 0;
        int R = -1;
        vector<vector<int>> q;
        for(int i = 0;i<queries.size();i++){
            q.push_back({queries[i][0],queries[i][1],queries[i][2],i});
        }
        sort(q.begin(),q.end(),cus);
        mo moe;
        
        vector<int> ans(q.size());
        for(auto it : q){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int i = it[3];

            while(R<r) moe.add(arr[++R]);
            while(L>l) moe.add(arr[--L]);

            while(R>r) moe.del(arr[R--]);
            while(L<l) moe.del(arr[L++]);

            ans[i] = moe.show(k)*2;
        }

        return ans;
    }
};