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
    int n,k,d;
    cin >> n>> k >> d;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<pair<int,int>>b(n+1);
    for(int i = 1;i<=n;++i){
        b[i].first = a[i]%d;
        b[i].second = a[i];
    }
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+1, vector<int>(d+1,-1)));
    for(int i = 0;i<=n;++i){
        dp[i][0][0] = 0;
        dp[i][0][d] = 0;
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=min(k,i);++j){
            for(int l = 0;l<=d;++l){
                dp[i][j][l] = dp[i-1][j][l];
                if(b[i].first > l){
                    int val = (d+l)-b[i].first;
                    if(dp[i-1][j-1][val]!=-1)dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][val]+b[i].second);
                }
                if(l >= b[i].first){
                    if(dp[i-1][j-1][l-b[i].first]!=-1){
                        dp[i][j][l] = max(dp[i][j][l],dp[i-1][j-1][l-b[i].first] + b[i].second);
                    }
                }
            }
        }
    }
    int res = max(dp[n][k][0], dp[n][k][d]);
    cout << res;
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