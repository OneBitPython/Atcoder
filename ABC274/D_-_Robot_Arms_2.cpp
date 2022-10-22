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



void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    vector<int>a(n+1);
    for(int i =1;i<=n;++i)cin >> a[i];

    vector<map<int,bool>>dpy(n+2),dpx(n+2);
    dpy[2][0] = 1;
    int mx = 1e4;
    for(int i = 3;i<=n+1;++i){
        if(i%2){
            for(int j = -mx-30;j<=mx+30;++j){
                if(dpy[i-1].count(j-a[i-1]) || dpy[i-1].count(j+a[i-1]))dpy[i][j] = 1;   
            }
        }else dpy[i] = dpy[i-1];    
    }
    dpx[2][a[1]] = 1;
    dpx[3] = dpx[2];
    for(int i = 4;i<=n+1;++i){
        if(i%2==0){
            for(int j = -mx-30;j<=mx+30;++j){
                if(dpx[i-1].count(j-a[i-1]) || dpx[i-1].count(j+a[i-1]))dpx[i][j] = 1;   
            }
        }else dpx[i] = dpx[i-1];
    }
    if(dpx[n+1][x] && dpy[n+1][y])cout << "Yes" << endl;
    else cout << "No" << endl;
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