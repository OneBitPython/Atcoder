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
    int n,m;
    cin >> n >> m;
    vector<vector<vector<vector<vector<int>>>>>dp(n+1, vector<vector<vector<vector<int>>>>(m+1, vector<vector<vector<int>>>(m+1, vector<vector<int>>(m+1,vector<int>(4)))));
    for(int i = 1;i<=m;++i){
        dp[1][i][0][0][1] = 1;
    }
    int mod = 998244353;
    for(int i = 2;i<=n;++i){
        // find the number of sequences till i which have LIS 1
        for(int a = 1;a<=m;++a){
            for(int b = a;b<=m;++b){
                // array is in the order b,a
                // now you can swap b with a in the lis array
                dp[i][a][0][0][1] += dp[i-1][b][0][0][1];
                dp[i][a][0][0][1]%=mod;
            }
        }
    }
    for(int i = 2;i<=n;++i){
        // find number of sequences till i which have LIS  = 2
        for(int a = 1;a<=m;++a){
            for(int b = a+1;b<=m;++b){
                // array is of the form a,b
                // you can add b to the lis a so that lis array is a,b
                dp[i][a][b][0][2] += dp[i-1][a][0][0][1];
                dp[i][a][b][0][2] %= mod;
                for(int c = a;c<b;++c){
                    /// array is of the form c,b,a
                    // since c>=a, you can swap c with a and retain the same LIS
                    // lis will be {c,b} intially and will change to {a,b}
                    dp[i][a][b][0][2] += dp[i-1][c][b][0][2];
                    dp[i][a][b][0][2] %= mod;
                }
                for(int c = b;c<=m;++c){
                    // array is of the form a,c,b
                    // original LIS is {a,c}
                    // since b's lower bound is c, you can replace {a,c} with {a,b}
                    dp[i][a][b][0][2] += dp[i-1][a][c][0][2];
                    dp[i][a][b][0][2] %= mod;
                }
            }
        }
    }
    for(int i = 2;i<=n;++i){
        // find number of sequences till iwhich have LIS  = 3
        for(int a = 1;a<=m;++a){
            for(int b = a+1;b<=m;++b){
                for(int c = b+1;c<=m;++c){
                    // array is of the form a,b,c
                    // you have liS = {a,b} since c>b, you can add c to the lIS making it {a,b,c}
                    dp[i][a][b][c][3] += dp[i-1][a][b][0][2];
                    dp[i][a][b][c][3] %= mod;
                    for(int d = a;d<b;++d){
                        // array is of the form d,b,c,a
                        // LISis {d,b,c}. Since d >= a. You can replace d in this LIS with a

                        dp[i][a][b][c][3] += dp[i-1][d][b][c][3];
                        dp[i][a][b][c][3] %= mod;
                    }
                    for(int d = b;d<c;++d){
                        // array is of the form a,d,c,b
                        // LISis {a,d,c}. Since d >= b. You can replace d in this LIS with b

                        dp[i][a][b][c][3] += dp[i-1][a][d][c][3];
                        dp[i][a][b][c][3] %= mod;
                    }
                    for(int d = c;d<=m;++d){
                        // array is of the form a,b,d,c
                        // LISis {a,b,d}. Since d >= c. You can replace d in this LIS with c

                        dp[i][a][b][c][3] += dp[i-1][a][b][d][3];
                        dp[i][a][b][c][3] %= mod;
                    }
                }
            }
        }
    }
    int res = 0;
    for(int a = 1;a<=m;++a){
        for(int b = a+1;b<=m;++b){
            for(int c = b+1;c<=m;++c){
                res = ((res%mod)+(dp[n][a][b][c][3]%mod))%mod;
            }
        }
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