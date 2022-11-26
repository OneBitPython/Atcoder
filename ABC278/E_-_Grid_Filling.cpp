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


int f(int a,int b, int A, int B, int c, vector<vector<vector<int>>>&pref){
    return pref[A][B][c]- pref[a-1][B][c] - pref[A][b-1][c] + pref[a-1][b-1][c];
}
void solve()
{
    int n,m,k,h,w;
    cin >> n >> m >> k >> h >> w;
    vector<vector<int>>a(n+1, vector<int>(m+1));
    vector<vector<vector<int>>>pref(n+1, vector<vector<int>>(m+1, vector<int>(k+1)));
    vector<int>cnt(k+1);
    for(int i = 1;i<=n;++i){
        for(int j =1 ;j<=m;++j){
            cin >> a[i][j];
            cnt[a[i][j]]++;
            pref[i][j][a[i][j]] =pref[i-1][j][a[i][j]] + pref[i][j-1][a[i][j]] - pref[i-1][j-1][a[i][j]]+1;
            for(int c = 1;c<=k;++c){
                if(c==a[i][j])continue;
                pref[i][j][c] = pref[i-1][j][c] + pref[i][j-1][c] - pref[i-1][j-1][c];
            }
        }
    }
    for(int i = 1;i<=n-h+1;++i){
        for(int j = 1;j<=m-w+1;++j){
            int A = i+h-1, B = j+w-1;
            int res = 0;
            for(int c = 1;c<=k;++c){
                int get = f(i,j,A,B,c,pref);
                if(get < cnt[c])res++;
            }
            cout << res << ' ';
        }
        cout << endl;
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}