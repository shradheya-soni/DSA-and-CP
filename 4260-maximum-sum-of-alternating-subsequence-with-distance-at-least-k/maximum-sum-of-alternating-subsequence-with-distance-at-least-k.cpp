#define ll long long

struct node {
    ll maxi1,maxi;
    node() {
        maxi1=0,maxi = 0;
    }
    node(ll a,ll v) {
        maxi1 = a,maxi = v;
    }
};

vector<node> seg;


node merge(node left, node right) {
    return node(max(left.maxi1,right.maxi1),max(left.maxi,right.maxi));
}

void build_tree(int i, int j, vector<ll>& a, ll ind) {
    if (i == j) {
        seg[ind].maxi1 = a[i];
        seg[ind].maxi = a[i];
        return;
    }
    ll mid = (i + j) / 2;
    ll left = 2 * ind + 1;
    ll right = 2 * ind + 2;
    build_tree(i, mid, a, left);
    build_tree(mid + 1, j, a, right);
    seg[ind] = merge(seg[left], seg[right]);
}
void update(int i, int j, int pos, int ind, node val) {
    if (i == j) {
        seg[ind].maxi1 = max(seg[ind].maxi1, val.maxi1);
        seg[ind].maxi = max(seg[ind].maxi, val.maxi);
        return;
    }
    int mid = (i + j) / 2;
    if (pos <= mid) update(i, mid, pos, ind * 2 + 1, val);
    else update(mid + 1, j, pos, ind * 2 + 2, val);
    seg[ind] = merge(seg[ind * 2 + 1], seg[ind * 2 + 2]);
}
node query(int i, int j, int l, int r, int ind) {
    if (r < i || j < l) return node();
    if (l <= i && j <= r) return seg[ind];
    int mid = (i + j) / 2;
    node left = query(i, mid, l, r, ind * 2 + 1);
    node right = query(mid + 1, j, l, r, ind * 2 + 2);
    return merge(left, right);
}

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n= nums.size();
        vector<vector<ll>> dp(n+1,vector<ll>(2,0));
        for(int i = 0;i<n;i++){
            dp[i][0] = nums[i];
            dp[i][1] = nums[i];
        }
        int m = *max_element(nums.begin(), nums.end());
        seg.assign(4*(m) + 5, node());
        vector<int> arr(m+5,0);
        int j = n-1;
        for(int i = n-1;i>=0;i--){
            if(i+k < n){
                update(0,m,nums[i+k],0,node(dp[i+k][0],dp[i+k][1]));
            }  
            
            ll q1 = query(0,m,nums[i]+1,m+1,0).maxi;
            ll q2 = query(0,m,0,nums[i]-1,0).maxi1;
            
            dp[i][1] = dp[i][1] + q2;
            dp[i][0] = dp[i][0] + q1;
            
        }
        ll ans = 0;
        for(int i = 0;i<n;i++){
            ans = max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
    
};