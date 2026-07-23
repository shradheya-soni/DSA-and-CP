class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> freq;
        for(char c : s) freq[c]++;

        priority_queue<pair<int,char>> pq;
        for(auto it : freq){
            pq.push({it.second, it.first});
        }

        string ans = "";
        while(pq.size() >= 2){
            auto x = pq.top(); pq.pop();
            auto y = pq.top(); pq.pop();

            ans += x.second;
            ans += y.second;

            if(--x.first) pq.push(x);
            if(--y.first) pq.push(y);
        }
        if(pq.empty()){
            return ans;
        }
        auto x = pq.top(); pq.pop();
        
        if(!ans.empty() && ans.back() == x.second && x.first >= 1) return "";
        if(x.first > 1ll){
            return "";
        }
        if(x.first == 1ll){
            ans += x.second;
        }
        return ans;
    }
};