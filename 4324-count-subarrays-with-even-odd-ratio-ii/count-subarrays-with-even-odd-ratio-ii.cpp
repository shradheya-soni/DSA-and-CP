#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// For unique elements
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// For duplicate elements (pass {value, index})
typedef tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]%2 == 0) nums[i] = b;
            else nums[i] = -a;

        }
        vector<long long> pre(n,0);
        pre[0] = nums[0];
        for(int i = 1;i<n;i++) pre[i] = nums[i] + pre[i-1];

        ordered_multiset st;
        st.insert({0,-1});
        long long ans = 0;
        for(int i = 0;i<n;i++){
            int num = st.size() - st.order_of_key({pre[i],-1});
            ans += num;
            st.insert({pre[i],i});
        }
        return ans;
    }
};