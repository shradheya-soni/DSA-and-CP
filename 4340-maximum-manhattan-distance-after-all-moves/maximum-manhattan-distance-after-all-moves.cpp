class Solution {
public:
    int maxDistance(string moves) {
        int x = 0,y = 0;
        int cnt = 0;
        int n = moves.length();
        for(int i = 0;i<n;i++){
            if(moves[i] == '_') cnt++;
            if(moves[i] == 'L') x--;
            if(moves[i] == 'U') y++;
            if(moves[i] == 'D') y--;
            if(moves[i] == 'R') x++;

        }
        if(x>=0) x += cnt;
        else x-=cnt;

        return abs(x)+abs(y);
    }
};