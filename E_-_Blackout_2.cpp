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

vector<int>id;
vector<pair<int,int>>sz;
int cnt = 0; // number of electrified cities
int root(int x){
    if(id[x] == x)return x;
    id[x] = root(id[x]);
    return id[x];
}

void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v)return;
    if(sz[v].first > sz[u].first)swap(v,u);
    id[v] = u;
    dbg(u,v,sz[u],sz[v]);
    if(sz[v].second == 0 && sz[u].second > 0){
        cnt+=sz[v].first;
    }
    if(sz[u].second == 0 && sz[v].second > 0){
        cnt+=sz[u].first;
    }
    sz[u].first += sz[v].first;
    sz[u].second += sz[v].second;
    
}

void solve()
{
    int n,m,e;
    cin >> n >> m >> e;
    vector<pair<int,int>>edges(e+1);
    vector<int>took;
    sz.resize(n+m+1);
    id.resize(n+m+1);
    for(int i = 1;i<=n+m;++i){
        id[i] = i;
        if(i > n)sz[i].second = 1;
        else sz[i].first = 1;
    }
    for(int i = 1;i<=e;++i)cin >> edges[i].first >> edges[i].second;
    int q;
    cin >> q;
    for(int i = 1;i<=q;++i){
        int v;
        cin >> v;
        took.pb(v);
    }
    merge(2,6);
    // for(int i = 1;i<=e;++i){
    //     if(binary_search(all(took), i))continue;
    //     merge(edges[i].first, edges[i].second);
    // }
    cout << cnt << endl;
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