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

int mod = 998244353;
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x % m + m) % m;
}
int modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (inv*a)%m;
}

// C function for extended Euclidean Algorithm (used to
// find modular inverse.

int p(int a,int b){
    // a^b using binary exponentiation
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%mod) * (a%mod))%mod;
        a = ((a%mod)*(a%mod))%mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<vector<int>>dp(n+1, vector<int>(x+1));
    dp[0][0] = p(2, n);
    for(int i = 1;i<=n;++i){
        dp[i][0]  = p(2,n);
        for(int j = 1;j<=x;++j){
            dp[i][j] = dp[i-1][j];
            if(j >= a[i]){
                dp[i][j] = ((dp[i][j]%mod)+(modDivide(dp[i-1][j-a[i]], 2, mod)%mod))%mod;
            }
        }
    }
    cout << dp[n][x] << endl;
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