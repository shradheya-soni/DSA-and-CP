#include<bits/stdc++.h>
using namespace std;
 
 
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    int low = 0;
    int high = n-1;
    sort(arr.begin(),arr.end());
    while(low <= n-1 && high >= 0){
        if(arr[low]*arr[high] == n-2){
            cout<<arr[low]<<" "<<arr[high]<<endl;
            return;
        }
        else if(arr[low]*arr[high] > n-2){
            high--;
        }
        else {
            low ++;
        }
        
    }
}
 
 
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
 
    while(t--){
        solve();
    }
 
    return 0;
}