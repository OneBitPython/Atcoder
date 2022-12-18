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

vector<int>a;
vector<int>id,sz;
int root(int x){
    if(id[x]==x)return x;
    return id[x]=root(id[x]);
}

bool merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return 0;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    return 1;
}
int n,m;
int p(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1){
            res = res * a;
            res%=m;
        }
        a = a * a;
        a%=m;
        b >>= 1;
    }
    return res%m;
}
void solve()
{
    cin >> n >> m;
    a.resize(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    id.resize(n+1);
    sz.resize(n+1,1);
    for(int i= 1;i<=n;++i)id[i] = i;
    vector<vector<int>>edges;
    for(int i= 1;i<=n;++i){
        for(int j = i+1;j<=n;++j){
            int cost = p(a[i],a[j])%m;
            cost+=(p(a[j],a[i]))%m;
            cost%=m;
            edges.pb({cost,i,j});
        }
    }
    int res = 0;
    sort(all(edges));
    reverse(all(edges));
    for(auto x : edges){
        if(merge(x[1],x[2]))res+=x[0];
    }
    cout << res << endl;
}      

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}