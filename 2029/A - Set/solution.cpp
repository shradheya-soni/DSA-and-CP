#include<bits/stdc++.h>
using namespace std;
 
 
long long find_num_of_multiples(long long l,long long r,long long num,long long k){
    long long cnt = r/num - (l-1)/num;
    return cnt;
}    
 
int solve(long long l , long long r ,long long k){
    long long low = l;
    long long high = r;
    if(low == high ){
        if(k != 1) return 0;
        else return 1;
    }
    while(low<=high){
        long long mid = (low + high)/2;
        if(find_num_of_multiples(l,r,mid,k) >= k){
            
            low = mid +1;
        }
        else{
            high = mid-1;
        }
    }
    return (high - l + 1);
}
 
 
 
 
 
int main(){
    int t;
    cin>>t;
    for(int i = 0 ; i<t;i++){
        long long l,r,k;
        cin>>l>>r>>k;
        cout<<solve(l,r,k)<<endl;
    }
    
 
    return 0;
 
}