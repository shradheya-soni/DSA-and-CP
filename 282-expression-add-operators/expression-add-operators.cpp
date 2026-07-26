class Solution {
public:
    vector<string> vec;
    
    // 1. Changed to long long to prevent multi-digit overflow
    long long ops(long long a, long long b, int c){
        if(c == 1) return a+b;
        if(c == 2) return a-b;
        if(c == 3) return a*b;
        return a;
    }

    // 2. Added 'long long a' as an argument because 'num[i-1]' no longer represents the whole previous number
    void f(string& num, int target, int i, long long sum, long long mul, string& ans, int op, long long a){
        
        if(i == num.length()){
            // Base case evaluation using 'a' instead of num[i-1]
            if((mul == -1 && ops(sum, a, op) == target) || (mul != -1 && ops(sum, mul, op) == target)){
                vec.push_back(ans);
                return;
            }
            return;
        }
        
        long long b = 0;
        string b_str = "";
        int original_len = ans.length(); // 3. Save length for dynamic backtracking

        // 4. Loop to form multi-digit numbers
        for(int j = i; j < num.length(); j++){
            if(j > i && num[i] == '0') break; // Prevent leading zeros
            
            b = b * 10 + (num[j] - '0');
            b_str += num[j];

            if(mul == -1){
                ans += "+" + b_str;
                f(num, target, j+1, ops(sum, a, op), -1, ans, 1, b);
                ans.erase(original_len); // Clean backtracking
                
                ans += "-" + b_str;
                f(num, target, j+1, ops(sum, a, op), -1, ans, 2, b);
                ans.erase(original_len);
                
                ans += "*" + b_str;
                f(num, target, j+1, sum, a*b, ans, op, b);
                ans.erase(original_len);
            } 
            else{
                ans += "+" + b_str;
                f(num, target, j+1, ops(sum, mul, op), -1, ans, 1, b);
                ans.erase(original_len);
                
                ans += "-" + b_str;
                f(num, target, j+1, ops(sum, mul, op), -1, ans, 2, b);
                ans.erase(original_len);
                
                ans += "*" + b_str;
                f(num, target, j+1, sum, mul*b, ans, op, b);
                ans.erase(original_len);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        long long a = 0;
        string a_str = "";
        
        // Setup the first number (which can also be multi-digit) before starting recursion
        for(int j = 0; j < num.length(); j++){
            if(j > 0 && num[0] == '0') break;
            a = a * 10 + (num[j] - '0');
            a_str += num[j];
            
            string ans = a_str; // Initialize string with first number
            f(num, target, j+1, 0, -1, ans, 1, a);
        }
        
        return vec;
    }
};