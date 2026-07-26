class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long num = s;
        long long ans = s;
        if(n%2 == 1) n--;
        if(n%2 == 0){
            num += ((long long)(n/2ll))*(long long)m - ((long long) (n-1)/2ll);
        }
        return num;
        
    }
};