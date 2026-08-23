class Solution {
public:
    bool sumGame(string num) {
        int l = 0;
        int ls = 0;
        int r = 0;
        int rs = 0;
        int n = num.length();

        for(int i = 0;i<n;i++){
            if(i<(n/2)){
                if(num[i] == '?') l++;
                else ls += (num[i]-'0');
            }
            else {
                if(num[i] == '?') r++;
                else rs += (num[i]-'0');
            }
        }
        if(l == r){
            if(ls == rs) return false;
            else return true;
        }
        else if(l > r){  
            if(ls > rs){
                return true;
            }
            else{
                int s = l - r;
                int dif = rs - ls;
                
                    if(((s+1)/2)*9 > dif || (s/2)*9 < dif){
                        return true;
                    }
                    else return false;
                
                
            }
        }
        else{
            if(ls < rs){
                return true;
            }
            else{
                int s = r-l;
                int dif = ls - rs;
                
                    if(((s+1)/2)*9 > dif || (s/2)*9 < dif){
                        return true;
                    }
                    else return false;
            }
        }
    }
};