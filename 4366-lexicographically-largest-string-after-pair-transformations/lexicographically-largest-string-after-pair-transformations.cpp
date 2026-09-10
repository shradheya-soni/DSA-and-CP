class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans(n,"");

        for(int i = 0;i<n;i++){
            int x = nums[i];

            string s = "";
            int cnt = 0;
            while(x > 0){
                if(cnt == 25){
                    string temp(x,'z');
                    s += temp;
                    break;
                }
                if(x%2 == 1){
                    x--;
                    s += ('a'+cnt);
                }
                else{
                    x/=2;
                    cnt++;
                }
            }
            reverse(s.begin(),s.end());
            ans[i] =s;
        }
        return ans;
    }

};