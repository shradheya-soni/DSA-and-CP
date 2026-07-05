#include<bits/stdc++.h>
using namespace std;
 
 
string solve(string s,string r){
    int x = 0;
    int y = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] == '1') x++;
        else y++;
    }
    int i = 0;
    while(x>0 && y>0 && i<(r.length())){
        if(r[i] == '0') x--;
        else y--;
        i++;
    }
    if((x == 1 && y == 0) ||( x == 0 && y==1)) return "yes";
    else return "no";
}
 
 
 
int main(){
    int t ;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        string s;
        string r;
        cin>>s;
        cin>>r;
        
        cout<<solve(s,r)<<endl;
    }
    return 0;
}