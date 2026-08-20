class Solution {
public:
    bool consecutiveSetBits(int n) {
        int f = 0;
        for(int i = 1;i<32;i++){
            if(n&(1<<i) && n&(1<<(i-1))){
                f++;
            }
        }
        if(f==1) return true;
        return false;
    }
};