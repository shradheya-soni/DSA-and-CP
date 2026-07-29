class Solution {
public:
    bool isValid(string s) {
        map<char,char> mpp;
        mpp[')'] = '(';
        mpp['}'] = '{';
        mpp[']'] = '[';
        stack<char> st;
        for(auto it : s){
            if(mpp.find(it) != mpp.end()){
                if(st.empty()) return false;
                auto temp = st.top();
                st.pop();
                if(temp != mpp[it]) return false;
            }
            else st.push(it);
        }
        return (st.empty());
    }
    
};