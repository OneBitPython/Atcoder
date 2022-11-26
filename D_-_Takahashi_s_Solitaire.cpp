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


map<int,vector<int>>adj;
vector<int>a;
vector<bool>visited;
void dfs(int u, int &sum){
    sum+=a[u];
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v,sum);
    }
}
void solve()
{
    int n,m;
    cin >> n >> m;
    map<int,vector<int>>pos;
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        pos[v].pb(i);
        a.pb(v);
    }
    for(auto x : pos){
        int v = x.second.size();
        for(int j = 0;j<v-1;++j){
            adj[x.second[j]].pb(x.second[j+1]);
            adj[x.second[j+1]].pb(x.second[j]);
        }
    }
    for(int i =0;i<n;++i){
        int req = (a[i]+1)%m;
        if(pos[req].size() >= 1){
            adj[i].pb(pos[req][0]);
            adj[pos[req][0]].pb(i);
        }
    }   

    visited.resize(n+1);
    int res = 1e18;
    int s = accumulate(all(a),0ll);
    for(int i = 0;i<n;++i){
        if(!visited[i]){
            int sum = 0;
            dfs(i,sum);
            res = min(res, s-sum);
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