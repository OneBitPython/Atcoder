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
    int n,m;
    cin >> n >> m;
    vector<vector<char>>a(n, vector<char>(m));
    for(int i = 0;i<n;++i){
        string s;
        cin >> s;
        for(int j =0 ;j<m;++j)a[i][j] = s[j];
    }
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i = n-1;i>=0;--i){
        for(int j = m-1;j>=0;--j){
            if(a[i][j] == '#')continue;
            dp[i][j] = max(dp[i+1][j], dp[i][j+1]) + 1;

        }
    }
    cout << dp[0][0] << endl;
    // if(a[0][0] == '#'){
    //     cout << 0 << endl;
    //     return;
    // }
    // dp[0][0] = 1;
    // for(int i = 1;i<m;++i){
    //     if(a[0][i] == '#')break;
    //     dp[0][i] = dp[0][i-1]+1;
    // }
    // for(int i = 1;i<n;++i){
    //     if(a[i][0] == '#')break;
    //     dp[i][0] = dp[i-1][0]+1;
    // }
    // for(int i = 1;i<n;++i){
    //     for(int j = 1;j<m;++j){
    //         if(a[i][j] == '#')continue;
    //         int res = 0;
    //         if(a[i-1][j]!='#')res = max(res, dp[i-1][j]);
    //         if(a[i][j-1]!='#')res = max(res, dp[i][j-1]);
    //         dp[i][j] = 1+res;
    //     }
    // }
    // int res = 0;
    // for(int i = 0;i<n;++i){
    //     for(int j = 0;j<m;++j)res = max(res, dp[i][j]);
    // }
    // cout << res << endl;

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