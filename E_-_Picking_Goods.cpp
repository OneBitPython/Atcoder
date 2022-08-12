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

int f(vector<int>&a){
    return *max_element(all(a));
}

void solve()
{
    int R,C,c;
    cin >> R >> C >> c;
    vector<vector<int>>a(R+1, vector<int>(C+1));
    for(int i = 0;i<c;++i){
        int u,v,w;
        cin >> u >> v >> w;
        a[u][v] = w;
    }
    vector<vector<vector<int>>>dp(R+1, vector<vector<int>>(C+1, vector<int>(4))); // dp[i][j][k] maximum cost till i,j th value assuming that you take k values in this row (1<=k<=3)
    for(int i = 1;i<=R;++i){
        for(int j = 1;j<=C;++j){
            dp[i][j][1] = max(dp[i][j-1][1], f(dp[i-1][j])+a[i][j]);
            for(int k = 2;k<=3;++k)dp[i][j][k] = max(dp[i][j-1][k], dp[i][j-1][k-1]+a[i][j]);

        }
    }
    cout << f(dp[R][C]) << endl;
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