 int n;
vector<vector<int>> seg;
class Solution {
public:
   
    vector<int> merg(vector<int>&a,vector<int> &b){
        vector<int> ans;
        int l = 0;
        int r = 0;
        

        while(l<a.size() && r<b.size()){
            if(a[l] > b[r]){
                ans.push_back(b[r]);
               
                r++;
            }
            else{
                ans.push_back(a[l]);
                
                l++;
            }
        }
        while(l<a.size()){
            ans.push_back(a[l++]);
            
        }
        while(r < b.size()){
            ans.push_back(b[r++]);
        }

        return ans;
    }
    void f(vector<int>& a, int i ,int j,int idx ){
        if(i==j){
            seg[idx] = {a[i]};
            return;
        }
        int mid = (i+j)/2;
        f(a,i,mid,idx*2+1);
        f(a,mid+1,j,idx*2+2);

        seg[idx] = merg(seg[idx*2+1],seg[idx*2+2]);
    }

    int query(int i,int j,int l,int r,vector<int> &arr,int idx,int val){
        if(l<=i && j<=r){
            int ind = lower_bound(seg[idx].begin(),seg[idx].end(),val) - seg[idx].begin();
            
            return ind;
        }
        if(r<i || l>j) return 0;
        int mid = (i+j)/2;
        int a  = query(i,mid,l,r,arr,idx*2+1,val);
        int b  = query(mid+1,j,l,r,arr,idx*2+2,val);
        return a+b;

    }
    vector<int> countSmaller(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        n = nums.size();
        seg.assign(4*n+5,vector<int>());
        f(nums,0,n-1,0);
        vector<int> ans(n,0);
        for(int i = 1;i<n;i++){
            ans[i] = query(0,n-1,0,i-1,nums,0,nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};