class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long maxSum = 0;
        int positiveDeltaCount = 0;
        int minSacrifice = INT_MAX;
        
        for (int val : nums) {
            int xoredVal = val ^ k;
            
            if (xoredVal > val) {
                maxSum += xoredVal;
                positiveDeltaCount++;
                minSacrifice = min(minSacrifice, xoredVal - val);
            } else {
                maxSum += val;
                minSacrifice = min(minSacrifice, val - xoredVal);
            }
        }
        
        // If we have an odd number of nodes that benefit, we can't pair one of them.
        // We subtract the smallest difference to fix the parity.
        if (positiveDeltaCount % 2 != 0) {
            maxSum -= minSacrifice;
        }
        
        return maxSum;
    }
};