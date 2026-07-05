#include<bits/stdc++.h>
using namespace std;
 
 
long long solve(){
    long long n,b,c;
    cin>>n>>b>>c;
    if(b==0){
        if(c == n-2 || c == n-1 ) return n-1;
        else if(c < n-2) return -1;
        else return n;
    }
    if(n == b && b == c) return n;
    else{
        return (n - max((long long)0 , (n-c-1 +b)/b ));
    }
}
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
 
    return 0;
}