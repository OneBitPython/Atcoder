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

struct mergesorttree{
    int sz = 1;
    vector<vector<int>>seg,pref;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        pref.resize(sz*2);
    }

    void build(int x, int lx, int rx, vector<int>&a){
        if(rx-lx==1){
            if(lx < (int)(a.size()))seg[x].pb(a[lx]);
            return;
        }
        int m = (lx+rx)/2;
        build(2*x+1, lx, m, a);
        build(2*x+2, m, rx, a);
        merge(all(seg[2*x+1]), all(seg[2*x+2]), back_inserter(seg[x]));
    }

    void build(vector<int>&a){
        build(0,0,sz,a);
        for(int i = 0;i<sz*2;++i){
            if(!seg[i].empty())pref[i].pb(seg[i][0]);
            for(int j = 1;j<(int)(seg[i].size());++j)pref[i].pb(pref[i][j-1]+seg[i][j]);
        }
    }

    int sol(int x,int lx, int rx, int l, int r, int y){
        if(lx >= r || rx <= l)return 0ll;
        if(lx >= l && rx <= r){
            int pos = upper_bound(all(seg[x]),y)-seg[x].begin()-1;
            if(pos<0)return 0;
            return pref[x][pos];
        }
        int m = (lx+rx)/2;
        return sol(2*x+1, lx, m, l, r, y)+sol(2*x+2, m, rx, l, r, y);
    }

    int sol(int l, int r, int x){
        return sol(0,0,sz,l,r,x);
    }

    int sol2(int x,int lx, int rx, int l, int r, int y){
        // number of values < y
        if(lx >= r || rx <= l)return 0ll;
        if(lx >= l && rx<=r)return upper_bound(all(seg[x]),y)-seg[x].begin();

        int m = (lx+rx)/2;
        return sol2(2*x+1, lx, m, l, r, y)+sol2(2*x+2, m, rx, l, r, y);
    }

    int sol2(int l, int r, int x){
        return sol2(0,0,sz,l,r,x);
    }
};

void solve()
{
    int n,m,k;
    cin >> n >>m >> k;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    mergesorttree st;
    st.init(n);
    st.build(a);
    vector<int>res(n+1,-1);
    for(int i = 0;i<n;++i){
        if(i+m > n)break;
        int l = -1e10, r = 1e10;
        while(l+1< r){
            int t = (l+r)/2;
            int c = st.sol2(i,i+m,t);
            if(c < k)l = t;
            else r = t;
        }
        res[i] = r;
    }
    for(int i = 0;i<n;++i){
        if(i+m>n)break;
        int val = res[i];
        int cnt = st.sol2(i,i+m,val);
        int r = st.sol(i,i+m,val);
        if(cnt > k)r-=(val*(cnt-k));
        cout << r << ' ';

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