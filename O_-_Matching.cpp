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


int dp[22][(1ll<<21)+1];
int a[22][22];
void solve()
{
    int mod = 1e9+7;
    int n;
    cin >> n;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j)cin >> a[i][j];
    }
    int u = (1ll<<n);
    dp[0][0] = 1;
    for(int i = 1;i<=n;++i){
        dp[i][0] = 1;
        for(int j = 0;j<u;++j){
            if(__builtin_popcountll(j)!=i)continue;
            for(int k = 0;k<n;++k){
                int x = j;
                if(j&(1ll<<k)){
                    if(!a[i][k+1])continue;
                    x-=(1ll<<k);
                    dp[i][j] = ((dp[i][j]%mod)+(dp[i-1][x]%mod))%mod;
                }
            }
        }
    }
    cout << dp[n][u-1];
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