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
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    int n = s.size();
    vector<int>a;
    int sz = 0;
    for(int i = 0;i<n;++i){
        if(s[i] == 'F')sz++;
        else{
            a.pb(sz);
            sz = 0;
        }
    }
    a.pb(sz);
    vector<int>hori, verti;
    for(int i = 0;i<a.size();i+=2)hori.pb(a[i]);
    for(int i = 1;i<a.size();i+=2)verti.pb(a[i]);

    if(x < 0)x = hori[0] + (hori[0] - x);
    y = abs(y);
    int m = hori.size();
    int mx =max(n+1, x+1);
    vector<vector<int>>dp(max(1ll, m), vector<int>(mx+1));
    if(m > 0)dp[0][hori[0]] = 1;
    else dp[0][0] = 1;

    for(int i = 1;i<m;++i){
        for(int j = 0;j<=mx;++j){
            bool ok = 0;
            if(j+hori[i] <= mx)ok|=dp[i-1][j+hori[i]];
            if(j-hori[i] >= 0)ok|=dp[i-1][j-hori[i]];
            dp[i][j] = ok;
        }
    }
    m = verti.size();
    mx = max(n+1, y+1);
    vector<vector<int>>dp1(max(1ll, m), vector<int>(mx+1));
    if(m > 0)dp1[0][verti[0]] = 1;
    else dp1[0][0] = 1;
    for(int i = 1;i<m;++i){
        for(int j = 0;j<=mx;++j){
            bool ok = 0;
            if(j+verti[i] <= mx)ok|=dp1[i-1][j+verti[i]];
            if(j-verti[i] >= 0)ok|=dp1[i-1][j-verti[i]];
            dp1[i][j] = ok;
        }
    }
    cout << (dp.back()[x] && dp1.back()[y]?"Yes":"No");
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