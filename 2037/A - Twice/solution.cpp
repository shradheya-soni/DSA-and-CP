#include<bits/stdc++.h>
using namespace std;
 
 
int solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    int cnt = 0;
 
    for(int i = 0;i<21;i++){
        int k = 0;
        for(int j = 0;j<n;j++){
            if(i == arr[j]){
                k++;
            }
        }
        cnt += k/2;
    }
    return cnt;
}
 
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
 
    while(t--){
        cout<<solve()<<endl;
    }
 
    return 0;
}