class Solution {
public:
    string f(string s){
        int n = s.length();
        s = s+s;

        int i = 0;
        int j = 1;
        while(i<n && j<n){
            int k = 0;

            while(k<n && s[i+k] == s[j+k]) k++;

            if(k == n) break;

            if(s[i+k] > s[j+k]){
                i = i+k+1;
                if(i == j) i++;
            }
            else{
                j = j+k+1;
                if(i==j) j++;
            }
        }
        int ind = min(i,j);
        return s.substr(ind,n);
    }
    int minimumGroups(vector<string>& words) {
        map<string,int> mpp;
        for(int i = 0;i<words.size();i++){
            string e = "";
            string o = "";
            for(int j = 0;j<words[i].length();j++){
                if(j%2 == 0) e+=words[i][j];
                if(j%2 == 1) o+=words[i][j];

            }
            string ne = f(e);
            string no = f(o);
            string str = "";
            for(int j = 0;j<words[i].length();j++){
                if(j%2 == 0) str+=ne[j/2];
                if(j%2 == 1) str+=no[j/2];
            }

            mpp[str]++;

        }
        for(auto it : mpp) cout<<it.first<<" ";
        return mpp.size();
    }
};