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


vector<vector<int>>adj;
vector<int>in,cyclenode,par,visited;
int n;
void markcycle(){
    queue<int>q;
    for(int i = 1;i<=n;++i){
        if(in[i]==1)q.push(i);
    }
    vector<int>visited(n+1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        cyclenode[u] = 0;
        for(int v : adj[u]){
            in[v]--;
            if(in[v]==1)q.push(v);
        }
    }
}
void dfs(int u, int p, int sup){
    for(int v : adj[u]){
        if(v==p || cyclenode[v])continue;
        par[v] = sup;
        dfs(v,u,sup);
    }
}

void solve()
{
    cin >> n;
    in.resize(n+1);
    cyclenode.resize(n+1,1);
    adj.resize(n+1);
    visited.resize(n+1);
    par.resize(n+1);
    for(int i = 1;i<=n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        in[u]++;
        in[v]++;
    }
    markcycle();
    for(int i = 1;i<=n;++i){
        if(cyclenode[i])dfs(i,-1,i);
    }
    
    int q;
    cin >> q;
    while(q--){
        int u,v;
        cin >> u >> v;
        if(cyclenode[u] && cyclenode[v])cout << "No" << endl;
        else if(!cyclenode[u] && !cyclenode[v]){
            if(par[u] == par[v])cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            if(!cyclenode[v])swap(u,v);
            // u is a tree node
            if(par[u] == v)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
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