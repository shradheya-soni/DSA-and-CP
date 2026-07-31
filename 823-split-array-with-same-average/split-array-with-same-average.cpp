class Solution {
public:
    void f(vector<int> &arr, int i, int sum, vector<int> &vec) {
        int n = arr.size();
        if (i == n) {
            vec.push_back(sum);
            return ;
        }
        f(arr, i + 1,sum,vec);
        f(arr, i + 1,sum+arr[i],vec);

        return ;
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0;i<n;i++){
            nums[i] = nums[i]*n - sum;
        }
        vector<int> v1(n/2);
        vector<int> v2(n - n/2);
        for(int i = 0;i<n/2;i++){
            v1[i] = nums[i];
        }
        for(int i = 0;i<n-n/2;i++){
            v2[i] = nums[i + n/2];
        }

        vector<int> left;
        vector<int> right;

        f(v1,0,0,left);
        f(v2,0,0,right);
        
        int leftTotalSum = accumulate(v1.begin(), v1.end(), 0);

        unordered_set<int> rightSums(right.begin(), right.end());
        int rightTotalSum = accumulate(v2.begin(), v2.end(), 0);


        for(int i = 1; i < left.size(); i++) {
            int target = -left[i];
            
            if (rightSums.count(target)) {
                if (left[i] != leftTotalSum || target != rightTotalSum) {
                    return true; 
                }
            }
        }

        for (int i = 1; i < right.size(); i++) {
            if (right[i] == 0 ) {
                return true;
            }
        }

        return false;


    }
};