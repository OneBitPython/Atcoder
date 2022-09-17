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
int mod = 998244353;

int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}
 
// Function to compute a/b under modulo m
int modDivide(int a, int b, int m = 998244353)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
}
 
// C function for extended Euclidean Algorithm (used to
// find modular inverse.
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}

int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}

int s(int a, int d, int n){
    //n*(2a+(n-1)d)/2
    int f = ma(mm(n-1,d),mm(2,a));
    f = mm(n,f);
    return modDivide(f, 2,mod);
}





void solve()
{
    int n,m;
    cin >> n >> m;
    int q;
    cin >> q;
    while(q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        // rows from a->b
        // cols from c->d
        int res;
        if((a+c)%2){
            int terms = (d-c+1)/2;
            int sum = s(ma(c+1,mm(a-1,m)), 2, terms);
            sum%=mod;
            int rows = (b-a+2)/2;
            sum = mm(sum,rows);

            int su = s(0, 2, rows);
            su%=mod;
        
            su = mm(su,m);
            su = mm(su, terms);
            int first = ma(su,sum);

            terms = (d-c+2)/2;
            sum = s(ma(c,mm(a-1,m)), 2, terms);
            sum%=mod;
            rows = (b-a+1)/2;
            sum = mm(sum,rows);
            sum%=mod;
            su = s(1,2,rows);
            su = mm(su, m);
            su = mm(su,terms);
            su%=mod;
            int second = ma(su,sum);
            second%=mod;
            res = ma(first,second);
        }else{
            int terms = (d-c+2)/2;
            int sum = s(ma(c,mm(a-1,m)), 2, terms);
            sum%=mod;
            int rows = (b-a+2)/2;
            sum = mm(sum,rows);

            int su = s(0, 2, rows);
            su%=mod;
        
            su = mm(su,m);
            su = mm(su, terms);
            int first = ma(su,sum);

            terms = (d-c+1)/2;
            sum = s(ma(c+1,mm(a-1,m)), 2, terms);
            sum%=mod;
            rows = (b-a+1)/2;
            sum = mm(sum,rows);
            sum%=mod;
            su = s(1,2,rows);
            su = mm(su, m);
            su = mm(su,terms);
            su%=mod;
            int second = ma(su,sum);
            second%=mod;
            res = ma(first,second);
        }
        cout <<res%mod << endl;
    }
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