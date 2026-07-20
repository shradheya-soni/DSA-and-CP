class Solution {
public:
    long long cnt = 0;
    void f(vector<int>& arr,int l,int r){
        int mid = (l+r)/2;
       vector<int> ans;
        int i = l;
        int j = mid;
        while(i<mid && j<r){
            if(arr[i] >= arr[j]){
                ans.push_back(arr[j]);
                j++;
            }
            else{
                cnt += r - j ;

                ans.push_back(arr[i]);
                i++;
            }
        }
        while(i<mid){
            ans.push_back(arr[i]);
            i++;
        }
        while(j<r){
            ans.push_back(arr[j]);
            j++;
        }
        for(int i = l;i<r;i++){
            arr[i] = ans[i-l];
        }
        return;
    }
    void merge(vector<int>& arr,int i,int j){
        if(j-i <= 1){
            return ;
        }
        int mid = (i+j)/2;
        merge(arr,i,mid);
        merge(arr,mid,j);

        return f(arr,i,j);
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] != target) {
                arr[i] = -1;
            } else {
                arr[i] = 1;
            }
        }

        vector<int> pre(n+1, 0);
        
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + arr[i];
        }
        
        merge(pre,0,n+1);
        return cnt;
    }
};