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


vector<vector<int>>edges;
vector<int>id, sz;

int root(int x){
    if(x == id[x])return x;
    return id[x] = root(id[x]);
}

void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v)return;
    if(sz[v] > sz[u])swap(u,v);
    sz[u]+=sz[v];
    id[v] = u;
}

bool unconnected(int u, int v){
    return root(u)!=root(v);
}

void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    
    id.resize(n+1);
    sz.resize(n+1,1);
    for(int i = 1;i<=n;++i)id[i] = i;
    for(int i = 0;i<m;++i){
        int u,v,w;
        cin >> u >> v >> w;
        edges.pb({u, v, w, -1});
    }
    for(int i = 0;i<q;++i){
        int u,v,w;
        cin>> u >> v >> w;
        edges.pb({u, v, w, i});
    }
    sort(all(edges), [&](auto one, auto two){
        return one[2] < two[2];
    });
    vector<string>res(q, "No");
    for(auto x : edges){
        if(x[3]!=-1){
            if(unconnected(x[0], x[1]))res[x[3]] = "Yes";
            continue;
        }
        merge(x[0], x[1]);
    }
    for(auto x : res)cout << x << endl;

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