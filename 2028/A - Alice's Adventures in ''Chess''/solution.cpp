#include<bits/stdc++.h>
using namespace std;
 
 
 
string solve(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
 
    
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    for(int i = 0;i<n;i++){
        if(s[i] == 'N') dy += 1;
        else if(s[i] == 'S') dy -= 1;
        else if(s[i] == 'W') dx -= 1;
        else if(s[i] == 'E') dx += 1;
    }
 
for(int j = 0 ; j < (1e5); j++){
 
    for(int i = 0;i<n;i++){
        if(x == a && y == b) return "YES";
        if(s[i] == 'N') y += 1;
        else if(s[i] == 'S') y -= 1;
        else if(s[i] == 'W') x -= 1;
        else if(s[i] == 'E') x += 1;
    }
    
    if(dx != 0 && dy != 0){
    if((((a-x)%dx == 0 ) && ((b-y)%dy == 0)) && ((a-x)/dx == (b-y)/dy) && ((a-x)/dx >= 0)) return "YES";
    }
    if(dx == 0 && dy == 0) break;
    
}
    
    return "NO"; 
 
}
 
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
 
    }
}