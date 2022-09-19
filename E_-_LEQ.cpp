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

int mod =  998244353;
int mp(int a, int b){
    int res = 1;
    while(b){
        if(b&1){
            res = ((res%mod)*(a%mod))%mod;
        }
        a = ((a%mod)*(a%mod))%mod;
        b/=2;
    }
    return res;
}

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int modInverse(int b, int m)
{
    int x, y; 
    int g = gcdExtended(b, m, &x, &y);
 
    if (g != 1)
        return -1;
 
    return (x%m + m) % m;
}
 

int md(int a, int b, int m=mod)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
}

struct segtree{
    int sz = 1;
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx == 1){
            seg[x] = ((seg[x]%mod)+(v%mod))%mod;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i,v);
        seg[x] = ((seg[2*x+1]%mod)+(seg[2*x+2]%mod))%mod;
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 0ll;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return ((sol(2*x+1, lx, m, l, r)%mod)+(sol(2*x+2, m, rx, l, r)%mod))%mod;
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
/*
two values a[i] <= a[j] such that i,j will form 2^(j-i-1) subsequences
let current index be i and let a[j], a[k], a[l] be greater >= a[i] and j > i and k > i and l > i

2^(j-i-1) + 2^(k-i-1)+2^(l-i-1)
2^j/2^(i+1) + 2^k/2^(i+1) + 2^l/2^(i+1)

1/2^(i+1) * [2^k + 2^ j + 2^l]
*/

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    map<int,vector<int>>idxs;
    for(int i = 0;i<n;++i)idxs[a[i]].pb(i);
    set<int>st(all(a));
    int g = 0;
    vector<int>c(n);
    for(auto x : st){
        for(auto y : idxs[x])c[y] = g;
        g++;
    }
    segtree seg;
    seg.init(n);
    int res = 0;
    for(int i = n-1;i>=0;--i){
        int val = seg.sol(c[i],g+1);
        val = md(val, mp(2,i+1));
        res = ((res%mod)+(val%mod))%mod;
        seg.set(c[i],mp(2,i));
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