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
    
    bool check(int n) {
        if (n < 0) return false;
        int root = sqrt(n);
        return (root * root == n);
    }
    int nC2(int n) {
        if (n < 2) return 0;
        return n * (n - 1) / 2;
    }
    vi vertex;
    vi sub;
    vvi adj;
    int n;
    int ans = 0;
    int f1(int node,int par){
        sub[node] = 1;
        for(auto it : adj[node])if(it != par){
            sub[node] += f1(it,node);
        }
        return sub[node];
    }
    stack<int> st;
    void dfs(int node,int par){
 
        if(check(vertex[node]*vertex[node]*vertex[node])){
            int temp = 1;
            if(!st.empty()){
                temp = st.top();
            }
            ans += nC2(sub[node]) * (sub[temp] - sub[node] ) + nC2(sub[temp] - sub[node] ) *sub[node];
            st.push(node);
 
        }
        for(auto it : adj[node])if(it != par){
            dfs(it,node);
        }
        if(!st.empty() && node == st.top()) st.pop();
    }
    void sol() {
    ans= 0;
    cin>>n;
    vertex.assign(n+1,0);
    for(int i = 1;i<=n;i++) cin>>vertex[i];
    adj.assign(n+1,vi());
    sub.assign(n+1,0);
    
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    f1(1,0);
 
    for(int i = 1;i<=n;i++){
        if(check(vertex[i])){
            vi temp;
            temp.pb(1); 
            int res =n-1;
            
        
            for(auto it : adj[i]){
                if(sub[it] < sub[i]){
                    temp.pb(sub[it]);
                    res -= sub[it];
                }
            }
            if(res > 0) temp.pb(res);
            
            int sum1 = n, sum2 = 0, sum3 = 0;
            for(int j = 0;j<temp.size();j++){
                sum2 += temp[j]*temp[j];
                sum3 += temp[j]*temp[j]*temp[j];
            }
  
            ans += ((sum1*sum1*sum1) -3*(sum1*sum2) +2*(sum3))/6;
        }
    }
 
    cout << ans;
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