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

int n,k;
vector<int>a;
bool pos(int x){
    if(a[x] >= k)return 1;
    vector<int>b;
    b.pb(0);
    for(int i = 1;i<=n;++i){
        if((i-1)!=x)b.pb(a[i-1]);
    }
    sort(all(b));
    int m = (b.size())-1;
    vector<vector<int>>dp(m+1, vector<int>(k+1));
    dp[0][0] = 1;
    dbg(b, x, m);

    for(int i = 1;i<=m;++i){
        dp[i][0] = 1;
        for(int j = 1;j<=k;++j){
            dp[i][j] = dp[i-1][j];
            if(j >= b[i]){
                dp[i][j] = dp[i-1][j-b[i]]|dp[i-1][j];
            }
        }
    }
    int req = k-a[x];
    dbg(dp, req);
    for(int i = req;i<k;++i){
        if(dp[m][i])return 1;
    }
    return 0;
}
void solve()
{
    cin >> n >> k;
    a.resize(n);
    for(int i = 0;i<n;++i)cin >> a[i];
    int l = -1, r = n;
    sort(all(a));
    dbg(a);
    while(l+1 < r){
        int m = (l+r)/2;
        if(pos(m))r = m;
        else l = m;
        dbg(l,r);
    }
    cout << r << endl;
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