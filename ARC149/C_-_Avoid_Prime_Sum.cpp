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
    int n;
    cin >> n;
    if(n==3){
        cout << "1 3 5" << endl;
        cout << "8 6 9" << endl;
        cout << "4 2 7" << endl;
        return;
    }
    vector<vector<int>>a(n+2, vector<int>(n+2));
    int x = 1;
    int bound = n * n;
    vector<int>isprime(2*bound+1,1);
    isprime[0] = isprime[1] = 0;
    for(int i = 2;i*i<=2*bound;++i){
        if(isprime[i]){
            for(int j = i*i;j<=2*bound;j+=i)isprime[j] = 0;
        }
    }
    set<int>unselected;
    for(int i = 2;i<=bound;i+=2)unselected.insert(i);
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            if(x > bound){
                for(auto y : unselected){
                    vector<int>neigh;
                    if(i > 1)neigh.pb(a[i-1][j]);
                    if(j > 1)neigh.pb(a[i][j-1]);
                    bool ok = 1;
                    for(auto z : neigh){
                        if(isprime[z+y])ok = 0;
                    }
                    if(ok){
                        a[i][j] = y;
                        break;
                    }
                }
                unselected.erase(a[i][j]);
                continue;
            }
            a[i][j] = x;
            x+=2;
            
        }
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            cout << a[i][j] << ' ';
        }
        cout << endl;
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