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

int n,m,q;
vector<vector<int>>edges;
vector<int>id, sz;

int root(int x){
    if(x == id[x])return x;
    id[x] = root(id[x]);
    return id[x];
}

bool merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v)return 0;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    return 1;
}

void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    id.resize(n+1);
    sz.resize(n+1, 1);
    for(int i = 1;i<=n;++i){
        id[i] = i;
    }
    for(int i = 0;i<m;++i){
        int u,v,w;
        cin >> u >> v >> w;
        edges.pb({w, u, v});
    }    
    sort(all(edges));
    vector<set<pair<int,int>>>mst(n+1); // edges of the mst formed
    // cost of edge between {u,v}
    map<pair<int,int>, int>cost;
    for(auto x : edges){
        if(merge(x[1], x[2])){
            mst[x[1]].insert({x[2], x[0]});
            mst[x[2]].insert({x[1], x[0]});
            cost[{x[1], x[2]}] = x[0];
            cost[{x[2], x[1]}] = x[0];
        }
    }
    vector<int>indegree(n+1); // indegree based on mst graph
    for(int i = 1;i<=n;++i){
        for(auto x : mst[i]){
            indegree[x.first]++;
        }
    }
    int mx = -1;
    vector<int>maxes(n+1);
    for(int i = 1;i<=n;++i){
        int curr = 0;
        for(auto x : mst[i]){
            curr = max(curr, x.second);
        }
        maxes[i] = curr;
        if(indegree[i] == 1)continue;
        for(auto x : mst[i]){
            if(indegree[x.first] > 1)mx = max(mx, x.second);
        }
    }
    while(q--){
        int u,v,w;
        cin >> u >> v >> w;
        if(cost.count({u, v})){
            if(w < cost[{u, v}]){
                cout << "Yes" << endl;
            }else cout << "No" << endl;
            continue;
        }
        int curr = mx;
        if(indegree[u] == 1)curr = max(curr, maxes[u]);
        if(indegree[v] == 1)curr = max(curr, maxes[v]);
        if(w < curr)cout << "Yes" << endl;
        else cout << "No" << endl;
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