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


struct segmn{
    int sz = 1;
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx - lx == 1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i , int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lx >= r || rx <= l)return 1e18;

        if(lx >= l && rx <= r)return seg[x];
        int m =(lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }

};


struct segmx{
    int sz = 1;
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx - lx == 1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i , int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lx >= r || rx <= l)return 1e18;

        if(lx >= l && rx <= r)return seg[x];
        int m =(lx+rx)/2;
        return max(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }

};

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    multiset<int>st;
    for(auto x : a){
        st.insert(x);
    }
    int res = 0;
    while(st.size() > 1){
        int min_ = *st.begin();
        int max_ = *st.rbegin();
        st.erase(--st.end());
        if((max_%min_) > 0)st.insert(max_ % min_);
        res++;
    }
    dbg(st);
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