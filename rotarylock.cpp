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

int ma(int &a, int &b, int &mod){
    return ((a%mod)+(b%mod))%mod;
}

struct segtree{
    vector<int>seg;
    int sz = 1;
    void init(int &n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int &i, int &v, int &mod){
        if(rx-lx==1){
            seg[x] = ma(seg[x], v, mod);
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v,mod);
        else set(2*x+2, m, rx, i, v, mod);
        seg[x] = ma(seg[2*x+1], seg[2*x+2], mod);
    }

    void set(int i, int v, int mod){
        set(0,0,sz,i,v,mod);
    }   

    int sol(int x, int lx, int rx, int &l, int &r,int &mod){

        if(lx >= r || rx <= l)return 0ll;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        int left = sol(2*x+1,lx,m,l,r,mod);
        int right = sol(2*x+2,m,rx,l,r,mod);
        return ma(left,right,mod);
    }

    int sol(int l, int r, int &mod){
        return sol(0,0,sz,l,r, mod);
    }
};
void solve()
{
    int n,q,k;
    cin >> n >> q >> k;
    int m = (1ll<<k);
    segtree st;
    st.init(n);
    while(q--){
        int t;
        cin >> t;
        if(t==0){
            int d,s;
            cin >> d >> s;
            st.set(d-1,s,m);
        }else{
            int x;
            cin >> x;
            cout << st.sol(0,x,m)%m << endl;
        }
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}