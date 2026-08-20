class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long t = 0;
        int m = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> last = intervals[0];
        for(int i = 1;i<(int)intervals.size();i++){
            if(last[1] + 1 < intervals[i][0]){
                t += last[1] - last[0] + 1;
                last = intervals[i];
            }
            else{
                last[0] = min(last[0],intervals[i][0]);
                last[1] = max(last[1],intervals[i][1]);
            }
        }

        t += last[1] - last[0] +1;
        
        
        long long cnt = brightness/3;
        if(brightness%3 != 0) cnt ++;

        return cnt*t;
    }
};