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

long double d(pair<long double,long double>c,pair<long double,long double>g)
{
    // Calculating distance
    long double x1 = c.first, y1 = c.second;
    long double x2 = g.first, y2 = g.second;
    return sqrtl(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

void solve()
{
    int n,m;
    cin >> n >> m;
    int c = n+m;
    vector<pair<int,int>>a(c);
    for(int i = 0;i<c;++i)cin >> a[i].first >> a[i].second;
    int u = (1ll<<c);
    vector<vector<double>>dp(u,vector<double>(c));
    double res = 1e18;
    for(int i = 1;i<u;++i){
        int t = __builtin_popcount(i);
        if(t > 1)continue;
        for(int j = 0;j<c;++j)dp[i][j] = d({0,0},a[j]);
    }
    for(int i = 1;i<u;++i){
        int t = __builtin_popcount(i);
        if(t <= 1)continue;
        int boost = 0;
        for(int j = n;j<c;++j){
            if(i&(1ll<<j))boost++;
        }
        for(int j = 0;j<c;++j){
            if(i&(1ll<<j)){
                int x= i-(1ll<<j);
                dp[i][j] = 1e18;
                int acc = boost;
                if(j >= n)acc--;
                for(int k = 0;k<c;++k){
                    if(x&(1ll<<k)){
                        double dist = d(a[j],a[k]);
                        double speed = pow(2,acc);
                        dp[i][j] = min(dp[i][j],dp[x][k]+(dist/speed));
                    }
                }
            }   
            
        }

    }
    for(int i = 1;i<u;++i){
        bool ok = 1;
        for(int j = 0;j<n;++j){
            if(i&(1ll<<j)){
                
            }else ok = 0;
        }

        if(!ok)continue;
        int boost  = 0;
        for(int j = n;j<c;++j){
            if(i&(1ll<<j))boost++;
        }
        for(int j = 0;j<c;++j){
            if(i&(1ll<<j)){
                double speed = pow(2,boost);
                double c = dp[i][j]+(d({0,0},a[j])/speed);
                res = min(res, c);
            }
        }

    }
    cout << fixed << setprecision(15) << res;
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