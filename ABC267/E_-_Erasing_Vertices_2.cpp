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
    vector<pair<int,int>>seg;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2, {-1,1e18});
    }

    pair<int,int>merge(pair<int,int>&one, pair<int,int>&two){
        // find one with smaller value
        if(one.second < two.second)return one;
        else return two;
    }

    void set(int x, int lx, int rx, pair<int,int>c){
        if(rx - lx == 1){
            seg[x] = c;
            return;
        }
        int m =(lx+rx)/2;
        if(c.first < m)set(2*x+1, lx, m, c);
        else set(2*x+2, m, rx, c);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void set(pair<int,int>c){
        set(0,0,sz,c); 
    }

    

    pair<int,int> sol(int x, int lx, int rx, int l, int r){
        if(l >= rx || r <= lx)return {0,1e18};
        if(l >= lx && r <= rx)return seg[x];
        int m = (lx+rx)/2;
        auto left = sol(2*x+1, lx, m, l, r);
        auto right = sol(2*x+2, m, rx, l, r);
        return merge(left,right);
    }

    pair<int,int> sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    int n,m;

    cin >> n >> m;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<vector<int>>adj(n);
    for(int i = 0;i<m;++i){
        int u,v;
        cin >> u >> v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }
    vector<int>cost(n);
    for(int i = 0;i<n;++i){
        int c = 0;
        for(int v : adj[i])c+=a[v];
        cost[i] = c;
    }
    segtree st;
    st.init(n);
    for(int i = 0;i<n;++i){
        pair<int,int>r = {i,cost[i]};
        st.set(r);
    }
    int res = 0;
    vector<int>removed(n);
    for(int i = 0;i<n;++i){
        pair<int,int>c = st.sol(0,n);
        res = max(res, c.second);
        // remove c.first
        removed[c.first] = 1;
        cost[c.first] = 1e18;
        pair<int,int>s = {c.first, 1e18};
        st.set(s);
        for(int v : adj[c.first]){
            cost[v] -= a[c.first];
            pair<int,int>k = {v,cost[v]};
            st.set(k);
        }
    }
    cout << res;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}