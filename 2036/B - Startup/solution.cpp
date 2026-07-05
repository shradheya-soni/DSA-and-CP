#include<bits/stdc++.h>
using namespace std;
 
 
int solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(k+1);
    for(int i = 0 ;i < k;i++){
        int b,c;
        cin>>b>>c;
        arr[b] += c;
    }
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    int profit = 0;
    if(n>k) return (accumulate(arr.begin(), arr.end(), 0));
    for(int i = 0; i<n ;i++){
        profit += arr[i];
    }
 
        return profit;
    
}
 
 
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}