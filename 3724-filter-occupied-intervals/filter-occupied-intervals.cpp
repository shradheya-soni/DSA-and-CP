class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n = occupiedIntervals.size();
        vector<vector<int>> arr;
        vector<pair<int,int>> occ;
        vector<pair<int,int>> fin;

        for(int i = 0;i<n;i++){
           occ.push_back({occupiedIntervals[i][0],occupiedIntervals[i][1]});

        }  
        sort(occ.begin(),occ.end());
        pair<int,int> last = occ[0];
        for(int i = 0;i<n;i++){
            if(occ[i].first <= 1+last.second){
                last = {(last.first),max(occ[i].second,last.second)};
            }
            else{
                fin.push_back(last);
                last = occ[i];
            }
        }      
        fin.push_back(last);
        int m = fin.size();
        sort(fin.begin(),fin.end());
        int s = freeStart;
        int e = freeEnd;
        vector<pair<int,int>> ans;
        for(int i = 0;i<m;i++){
            if(fin[i].first < s ){
                if(fin[i].second > e){
                    ans.push_back({fin[i].first,min(fin[i].second,s-1)});
                    ans.push_back({(e+1),fin[i].second});

                }
                else{   
                    ans.push_back({fin[i].first,min(fin[i].second,s-1)});
                }
            }

            else{
                if(fin[i].second > e){
                    ans.push_back({max(fin[i].first,e+1),fin[i].second});
                }
            }
        }
        vector<vector<int>> boom(ans.size(),vector<int>(2,0));
        for(int i = 0;i<ans.size();i++){
            boom[i][0] = ans[i].first;
            boom[i][1] = ans[i].second;

        }
        return boom;
    }
};