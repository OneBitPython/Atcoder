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


vector<int>color;
vector<vector<int>>adj;
bool bip(int u, int c){
    color[u] = c;
    for(int v : adj[u]){
        if(color[v]==-1){
            if(!bip(v,1-c))return 0;
        }else{
            if(color[u]==color[v])return 0;
        }
    }
    return 1;
}

void dfs(int u, vector<int>&visited, vector<int>&p){
    p.pb(u);
    visited[u] = 1;
    for(int v : adj[u]){
        if(!visited[v])dfs(v,visited,p);
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;
    color.resize(n+1, -1);
    adj.resize(n+1);
    for(int i= 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool ok = 1;
    for(int i = 1;i<=n;++i){
        if(color[i]==-1){
            if(bip(i,0)==0){
                ok = 0;
            }
        }
    }
    if(!ok){
        cout << 0 << endl;
        return;
    }
    vector<int>visited(n+1);
    int res = 0;
    for(int i = 1;i<=n;++i){
        if(!visited[i]){
            vector<int>p;
            dfs(i,visited,p);
            int m = p.size();
            res+=(m*(n-m));
        }
    }
    res/=2;
    visited = vector<int>(n+1);
    for(int i = 1;i<=n;++i){
        if(!visited[i]){
            vector<int>p;
            dfs(i,visited,p);
            int g = 0, r = 0;
            int tot = 0;
            for(auto x : p){
                g+=(!color[x]);
                r+=color[x];
            }
            for(auto x : p){
                if(color[x]==1){
                    // group r
                    tot+=(g-adj[x].size());
                }else tot+=(r-adj[x].size());
            }
            res+=(tot/2);
        }
    }
    cout << res;
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