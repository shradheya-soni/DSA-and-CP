// I AM NOT HERE TO PARTICIPATE, I AM HERE TO DOMINATE
#define JAI ios::sync_with_stdio(false);
#define SHREE cin.tie(NULL);
#define RAM cout.tie(NULL);
#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define pb push_back
#define ppb pop_back
#define int long long
#define mp make_pair
using vpi = vector < pair < int, int >> ;
using pi = pair < int, int > ;
using vi = vector < int > ;
using mapi = map < int, int > ;
using vvi = vector < vector < int >> ;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x)(int)(x).size()
const int inf = 9e17;
const int mod = 1e9 + 7;
#define DEBUG(x) cerr << #x << ": " << x << '
'
template < typename T, typename Y >
    istream & operator >> (istream & is, pair < T, Y > & p)
    {
        is >> p.first >> p.second;
        return is;
    }
template < typename T, typename Y >
    ostream & operator << (ostream & os, pair < T, Y > p)
    {
        os << p.first << ' ' << p.second << ' ';
        return os;
    }
template < typename T >
    istream & operator >> (istream & is, vector < T > & v)
    {
        for (auto & i: v)
            is >> i;
        return is;
    }
template < typename T >
    ostream & operator << (ostream & os, vector < T > v)
    {
        for (auto & i: v)
            os << i << ' ';
        return os;
    }
 
int power(int base, int ex, int mod) {
    int res = 1;
    while (ex > 0) {
        if (ex % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        ex /= 2;
    }
    return res;
}
 
void sol() {
    int n;cin>>n;
    vi arr(n);cin>>arr;
 
    if(n%2 == 1){
        cout<<"NO";
        return;
    }
    int s = accumulate(all(arr),0);
    if(s == 0) cout<<"YES";
    else if((s/2)%2 == 0 ) cout<<"YES";
    else cout<<"NO";
}
 
signed main() {
 
    JAI SHREE RAM
 
    int t;
    cin >> t;
 
    while (t--) {
        sol();
        cout << endl;
    }
 
 
 
}