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

bool valid3(int a, int b, int c){
    bool ok =  1;
    if(a == 0 && b == 2 && c == 1)ok = 0;
    if(a == 0 && b == 1 &&  c == 2)ok = 0;
    if(a == 2 && b == 0 && c == 1)ok = 0;
    return ok;
}

bool valid(int a, int b, int c){
    bool ok = 1;
    if (a == 0 && b == 2 && c == 1)ok = 0;
    return ok;
}

void solve()
{
    int n;
    cin >> n;
    /*
    a = 0, 'A'
    a = 1, 'C'
    a = 2, 'G',
    a = 3, 'T'
    */
    if(n == 1){
        cout << 4;
        return;
    }else if(n == 2){
        cout << 16;
        return;
    }
    int mod = 1e9+7;
    vector<vector<vector<vector<int>>>>dp(n+1, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4))));
    for(int a = 0;a<4;++a){
        for(int b = 0;b<4;++b){
            for(int c = 0;c<4;++c){
                if(valid3(c,b,a))dp[3][c][b][a] = 1;
            }
        }
    }
    for(int i = 4;i<=n;++i){
        for(int a = 0;a<4;++a){
            for(int b = 0;b<4;++b){
                for(int c = 0;c<4;++c){
                    if(valid3(c,b,a)){
                        for(int d = 0;d<4;++d){
                            if(valid3(d,c,b) && valid(d,b,a) && valid(d,c,a)) dp[i][d][c][b] = (dp[i][d][c][b] + dp[i-1][c][b][a])%mod;
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for(int a = 0;a<4;++a){
        for(int b = 0;b<4;++b){
            for(int c = 0;c<4;++c){
                if(valid3(c,b,a)) res=(res+dp[n][c][b][a])%mod;
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