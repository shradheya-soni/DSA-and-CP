#include<bits/stdc++.h>
using namespace std;
 
 
string solve(){
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
 
    for(int i = 0;i<n-1;i++){
        int seminotes = arr[i+1] - arr[i];
        if(abs(seminotes) != 5 && abs(seminotes) != 7 ){
            return "NO";
        }
    }
    return "YES";
}
 
 
 
 
int main(){
    int t ;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}