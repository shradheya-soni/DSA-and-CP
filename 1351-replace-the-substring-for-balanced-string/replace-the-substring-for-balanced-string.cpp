class Solution {
public:
    vector<int> arr;
    bool f(vector<int>& temp){
        for(int i = 0;i<4;i++){
            if(temp[i] > 0) return 0;
        }
        return 1;
    }
    bool check(int m,string &s){
        vector<int> temp = arr;

        int l = 0;
        int r = 0;
        while(r < m){
            char c = s[r];
            int num = -1;
            if(c == 'E') num = 0;
            if(c == 'Q') num = 1;
            if(c == 'R') num = 2;
            if(c == 'W') num = 3;

            temp[num]--;

            r++;
        }
        if(f(temp)) return 1;
        while(r<s.length()){
            char c = s[r];
            int num = -1;
            if(c == 'E') num = 0;
            if(c == 'Q') num = 1;
            if(c == 'R') num = 2;
            if(c == 'W') num = 3;

            temp[num]--;
            c = s[l];
            num = -1;
            if(c == 'E') num = 0;
            if(c == 'Q') num = 1;
            if(c == 'R') num = 2;
            if(c == 'W') num = 3;
            temp[num]++;
            if(f(temp)) return 1;
            l++;
            r++;


        }
        return 0;
    }
    int balancedString(string s) {

        vector<int> meas(4,0);
        for(auto c : s){
            int num = -1;
            if(c == 'E') num = 0;
            if(c == 'Q') num = 1;
            if(c == 'R') num = 2;
            if(c == 'W') num = 3;

            meas[num]++;
        }
        int n = s.length();
        arr.assign(4,0);
        for(int i = 0;i<4;i++){
            arr[i] = meas[i]-(n/4);
        }

        int l = 0;
        int r = n;
        int ans = 1e5;
        while(l<=r){
            int mid = (l+r)/2;
            if(check(mid,s)){
                r = mid-1 ;
                ans = min(ans,mid);
            }
            else l = mid+1;
        }
        return ans;
    }
};