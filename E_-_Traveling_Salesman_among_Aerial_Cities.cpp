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


int dist(vector<int>&a, vector<int>&b){
    //∣p−a∣+∣q−b∣+max(0,r−c).
    return abs(a[0] - b[0]) + abs(a[1] - b[1]) + max(0ll, b[2]-a[2]);
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>a(n, vector<int>(3));
    for(int i = 0;i<n;++i)cin >> a[i][0] >> a[i][1] >> a[i][2];
    int u = (1ll<<n);
    vector<vector<int>>dp(u, vector<int>(n,1e18)); // dp[i][j] stores the minimum cost to travel through a mask of i cities ending at city j and then going from city j back to city 1
    dp[0][0] = 0;
    for(int i = 1;i<u;++i){
        for(int j = 0;j<n;++j){
            if(i&(1ll<<j)){
                int x = i;
                x-=(1ll<<j);
                dp[i][j] = 1e18;
                for(int k = 0;k<n;++k){
                    int c = dp[x][k] + dist(a[k], a[j]);
                    dp[i][j] = min(dp[i][j], c);
                }
            }
        }
    }
    int res = 1e18;
    for(int i = 0;i<n;++i){
        res = min(res, dp[u-1][i] + dist(a[i], a[0]));
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