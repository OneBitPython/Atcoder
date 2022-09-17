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

    void clear(){
        seg.clear();
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx == 1){
            seg[x] += v;
            return;
        }

        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 0ll;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return sol(2*x+1, lx, m, l, r)+sol(2*x+2,m,rx,l,r);
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n),b(n);
    for(int &u : b)cin >> u;
    for(int &u : a)cin >> u;
    // a = number
    // b = color
    segtree st;
    st.init(n+1);
    st.set(a[0], 1);
    int tot_inv = 0;
    for(int i = 1;i<n;++i){
        tot_inv+=(st.sol(a[i]+1,n+1));
        st.set(a[i], 1);
    }
    vector<vector<int>>groups(n+1);
    for(int i = 0;i<n;++i){
        groups[b[i]].pb(a[i]);
    }
    st.clear();
    for(auto x : groups){
        if(x.empty())continue;
        // find inversion count of this group
        vector<int>c = x;
        st.set(c[0], 1);
        int m =c.size();
        for(int i = 1;i<m;++i){
            tot_inv-=(st.sol(c[i]+1, n+1));
            st.set(c[i], 1);
        }
        for(int i = 0;i<m;++i)st.set(c[i],-1);
    }
    cout << tot_inv;
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