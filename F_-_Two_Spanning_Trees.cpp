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

int n,m;
vector<vector<int>>adj, t1, t2; // dfs tree and bfs tree
vector<bool>visited;

void dfs(int u){
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v])continue;
        t1[u].pb(v);
        dfs(v);
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(n+1);
    t1.resize(n+1);
    t2.resize(n+1);
    visited.resize(n+1);
    for(int i = 0;i<m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // find dfs tree 
    dfs(1);
    queue<int>q;
    q.push(1);
    visited = vector<bool>(n+1);
    visited[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(visited[v])continue;
            visited[v] = 1;
            t2[u].pb(v);
            q.push(v);
        }
    }
    for(int i = 1;i<=n;++i){
        for(auto x : t1[i])cout << i << ' ' << x << endl;
    }
    for(int i = 1;i<=n;++i){
        for(auto x : t2[i])cout << i << ' ' << x << endl;
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