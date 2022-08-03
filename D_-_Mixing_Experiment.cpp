#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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
    int n,A,B;
    cin >> n >> A >> B;
    vector<vector<int>>a(n+1, vector<int>(3));
    for(int i = 1;i<=n;++i)cin >> a[i][0] >> a[i][1] >> a[i][2];
    
    int mxa, mxb;
    mxa = mxb = 401;
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(mxa+1, vector<int>(mxb+1, 1e18)));
    // minimum cost to obtain mixture of ration mxa : mxb from the first i values
    for(int i = 0;i<=n;++i)dp[i][0][0] = 0;
    for(int i = 1;i<=n;++i){
        for(int c = 1;c<=mxa;++c){
            for(int b = 1;b<=mxb;++b){
                dp[i][c][b] = min(dp[i][c][b], dp[i-1][c][b]);
                int newa = c-a[i][0];
                int newb = b-a[i][1];
                if(newa >= 0 && newb >= 0){
                    dp[i][c][b] = min({dp[i][c][b], dp[i-1][newa][newb]+a[i][2]});
                }
            }
        }
    }
    int res = 1e18;
    for(int i = 1;i<=n;++i){
        for(int c = 1;c<=mxa;++c){
            for(int b = 1;b<=mxb;++b){
                bool ratio = (A*b) ==  (B * c);
                if(ratio)res = min(res, dp[i][c][b]);
            }
        }
    }
    if(res == 1e18)cout << -1 << endl;
    else cout << res << endl;
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