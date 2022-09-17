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


bool adj(pair<int,int>a, pair<int,int>b){
    /*
    (i−1,j−1)
    (i−1,j)
    (i,j−1)
    (i,j+1)
    (i+1,j)
    (i+1,j+1)
    */
    vector<pair<int,int>>pos = {
        {-1,-1},
        {-1,0},
        {0,-1},
        {0,1},
        {1,0},
        {1,1}
    };
    for(auto x : pos){
        if(((a.first+x.first)==b.first) && (a.second+x.second)==(b.second))return 1;
    }
    swap(a,b);
    for(auto x : pos){
        if(((a.first+x.first)==b.first) && (a.second+x.second)==(b.second))return 1;
    }
    return 0;
}

vector<int>id,sz;
int root(int x){
    if(x==id[x])return x;
    id[x] = root(id[x]);
    return id[x];
}

void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;++i)cin >> a[i].first >> a[i].second;
    id.resize(n+1);
    sz.resize(n+1,1);
    for(int i = 0;i<n;++i)id[i] = i;
    for(int i = 0;i<n;++i){
        for(int j=  i+1;j<n;++j){
            if(adj(a[i], a[j])){
                merge(i,j);
            }
        }
    }
    int res = 0;
    for(int i = 0;i<n;++i){
        if(id[i] == i)res++;
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