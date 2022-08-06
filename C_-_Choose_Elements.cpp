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
    int n,k;
    cin >> n >> k;
    vector<int>a(n), b(n);
    for(int &u : a)cin >> u;
    for(int &u : b)cin >> u;
    vector<vector<int>>dp(n, vector<int>(2,0)); // dp[i][j] whether it is possible to take jth value in the ith position
    dp[0][0] = dp[0][1] = 1;
    for(int i = 1;i<n;++i){
        bool pos = 0, pos2 = 0;;
        // check if it is possible to take a[i]
        if(dp[i-1][0]){
            if(abs(a[i] - a[i-1]) <= k)pos = 1;
            if(abs(b[i] - a[i-1])<= k)pos2 = 1;
        }
        if(dp[i-1][1]){
            if(abs(a[i]-b[i-1]) <= k)pos = 1;
            if(abs(b[i] - b[i-1]) <= k)pos2 = 1;
        }
        dp[i][0] = pos;
        dp[i][1] = pos2;
    }
    cout << (dp[n-1][0] || dp[n-1][1]?"Yes":"No") <<endl;
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