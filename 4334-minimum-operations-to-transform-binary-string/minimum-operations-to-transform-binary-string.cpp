class Solution {
public:
    int f(string s1,string s2){
        int n = s1.length();
        int cnt = 0;
        for(int i = 0;i<n-1;i+=2){
            string t1 = s1.substr(i,2);
            string t2 = s2.substr(i,2);

            if(t1 == t2) continue;
            if(t2[0] != t2[1]){
                if(t1[0] == t1[1]){cnt += 2;}
            }
            if(t2[0] == t2[1]){
                if(t1[0] == t1[1]) cnt += 1;
                else cnt += 2;
            }
            
        }
        return cnt;
    }
    int minOperations(string s1, string s2) {
        int n = s1.length();
        if(n == 1 && s1[0] == '1' && s2[0] == '0'){
            return -1;
        }
        int cnt=  0;
        for(int i = 0;i<n;i++){
            if(s2[i] == '1' && s1[i] == '0'){
                s1[i] = '1';
                cnt++;
            }
        }

        for(int i = 0;i<n;i++){
            if(s1[i] != s2[i]){
                int l = 1;
                int r = 1;
                if(i>0) l = s1[i-1] == s2[i-1];
                if(i<n-1) r = s1[i+1] == s2[i+1];

                if(l==0 && r == 0){
                    cnt += f(s1.substr(i-1,2),s2.substr(i-1,2));
                    s1[i-1] = s2[i-1];
                    s1[i] = s2[i];
                }
                else if(l==0){
                    cnt += f(s1.substr(i-1,2),s2.substr(i-1,2));
                    s1[i-1] = s2[i-1];
                    s1[i] = s2[i];
                }
                else if(r == 0){
                    cnt += f(s1.substr(i,2),s2.substr(i,2));  
                    s1[i+1] = s2[i+1];
                    s1[i] = s2[i];
                }
                else{
                    if(i>0){
                        cnt += f(s1.substr(i-1,2),s2.substr(i-1,2));
                        s1[i-1] = s2[i-1];
                        s1[i] = s2[i];
                    }
                    
                    else {
                        cnt += f(s1.substr(i,2),s2.substr(i,2));
                        s1[i+1] = s2[i+1];
                    s1[i] = s2[i];
                    }
                }

            }

        }
    
        return cnt;
    }
};