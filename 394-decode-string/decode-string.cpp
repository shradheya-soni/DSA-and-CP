class Solution {
public:
    string f(string &s,int &i){
        string res = "";
        
        while(i<s.length() && s[i] != ']'){
            if(isdigit(s[i])){

                int num = 0;
                while(i < s.length() && isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i++;
                string t = f(s,i);
                i++;
                string str = "";
                for(int j=0;j<num;j++){
                    str += t;
                }
                res += str;
                
            }
            else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return f(s,i);
    }
};