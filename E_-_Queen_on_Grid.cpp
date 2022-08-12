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
int p = 1e9+7;
int f(int a, int b){
    return ((a%p)+(b%p))%p;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(n+1, vector<int>(m+1));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            char x;
            cin >> x;
            if(x == '.')a[i][j] = 1;
        }
    }
    vector<vector<int>>h(n+1, vector<int>(m+1)),d(n+1, vector<int>(m+1)), v(n+1, vector<int>(m+1)), dp(n+1, vector<int>(m+1));
    dp[0][0] = 1;

    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(i == 0 && j == 0)continue;
            if(!a[i][j])continue;
            if(j > 0)h[i][j] = f(h[i][j-1], dp[i][j-1]);
            if(i > 0)v[i][j] = f(v[i-1][j], dp[i-1][j]);
            if(i > 0 && j > 0)d[i][j] = f(d[i-1][j-1], dp[i-1][j-1]); 
            dp[i][j] = ((h[i][j]%p)+(v[i][j]%p)+(d[i][j]%p))%p;
        }
    }
    cout << dp[n-1][m-1];
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