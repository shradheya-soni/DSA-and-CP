class Solution {
public:

    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int m = stoll(s);
        if(n > m) swap(n,m);

        vector<int> arr(2000,1);
        for(int i = 2;i<2000;i++){
            if(arr[i] == 0) continue;
            for(int j = 2*i;j<2000;j += i){
                arr[j] = 0;
            }
        }
        int s1 = 0;
        for(int i = 2;i<2000;i++){
            if(arr[i] == 1 && i >= n && i <= m){
                s1+=i;
            }
        }
        return s1;

    }
};