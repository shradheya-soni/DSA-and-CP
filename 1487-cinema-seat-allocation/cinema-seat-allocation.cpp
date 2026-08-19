class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();

        map<int,vector<int>> mpp;
        for(int i = 0;i<m;i++){
           if(mpp.find(reservedSeats[i][0]) == mpp.end()) mpp[reservedSeats[i][0]] = vector<int>(10,0);
        }
        for(int i = 0;i<m;i++){
           mpp[reservedSeats[i][0]][reservedSeats[i][1]-1] = 1;
        }
        int cnt = 2*(n-mpp.size());
        
        for(auto &it : mpp){
            int l = 1;
            int r = 1;
            int c = 1;
            for(int i = 1;i<=4;i++){
                if(it.second[i] == 1) l = 0;
            }
            for(int i = 3;i<=6;i++){
                if(it.second[i] == 1) c = 0;
            }
            for(int i = 5;i<=8;i++){
                if(it.second[i] == 1) r = 0;
            }

            if(l == 1 && r == 1 && c == 1) cnt += 2;
            else if(l == 1 || r== 1 || c ==1 ) cnt += 1;
        }
        return cnt;


    }
};