#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");} 

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

struct segtree{
    int sz = 1;
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        
    }
 
    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = min(seg[2*x+1],seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 1e18;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r),sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
vector<vector<int>>adj;
vector<int>in,out,flat;
int t = 1;
void dfs(int u, int p){
    in[u] = t;
    flat[t] = u;
    t++;
    for(int v : adj[u]){
        if(v==p)continue;
        dfs(v,u);
    }
    out[u] = t;
    flat[t] = u;
    t++;
}
void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    flat.resize(2*n+1);
    in.resize(n+1);
    out.resize(n+1);
    for(int i = 2;i<=n;++i){
        int v;
        cin >> v;
        adj[v].pb(i);
    }
    dfs(1,-1);
    segtree st;
    st.init(2*n+2);
    for(int i = 1;i<=2*n;++i){
        st.set(i,flat[i]);
    }
    int q;
    cin >> q;
    while(q--){
        int t;
        cin>> t;
        if(t==1){
            int u,v;
            cin >> u >> v;
            int val = st.sol(in[u],in[u]+1);
            
            val = min(val, v);
            st.set(in[u],val);
            st.set(out[u],val);
        }else{
            int x;
            cin >> x;
            int best = x;
            while(1){
                int prev = best;
                best = st.sol(in[best],out[best]+1);
                if(best==prev)break;
            }
            cout << best << endl;
            st.set(in[x],best);
            st.set(out[x],best);
        }
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}