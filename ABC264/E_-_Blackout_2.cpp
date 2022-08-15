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

int n,m,e;
vector<int>id;
vector<int>in;
int root(int x){
    if(x == id[x])return x;
    id[x] = root(id[x]);
    return id[x];
}

void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v)return;
    if(u>n){
        // merge v to u
        id[v] = u;
        
    }else{
        id[u] = v;
    }
}

void solve()
{
    cin>> n >> m >> e;
    id.resize(n+m+1);
    in.resize(n+m+1);
    for(int i = 1;i<=n+m;++i)id[i] = i;
    vector<pair<int,int>>edges;
    for(int i = 0;i<e;++i){
        int u,v;
        cin >> u >> v;
        edges.pb({u, v});
        in[u]++;
        in[v]++;
        merge(u, v);
    }
    int q;
    cin >> q;
    int tot = 0;
    dbg(id[9],root(6));
    // while(q--){
    //     int x;
    //     cin >> x;
    //     int u = edges[x].first, v = edges[x].second;
    //     in[u]--;
    //     in[u]--;
    //     if(u<=n){
    //         if(u  <= n){

    //         }
    //     }
    // }
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