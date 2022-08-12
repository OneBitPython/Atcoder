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

vector<vector<vector<pair<int,int>>>>adj;
vector<vector<int>>color;
vector<vector<bool>>visited;
void dfs(int i, int j, int c){
    visited[i][j] = 1;
    color[i][j] = c;
    for(auto v : adj[i][j]){
        if(visited[v.first][v.second])continue;
        dfs(v.first, v.second, c);
    }
}
void solve()
{
    int sfdfs;
    cin >> sfdfs;
    int n,m;
    cin >>n >> m;
    int q;
    cin >> q;
    color = vector<vector<int>>(n+1, vector<int>(m+1));
    visited = vector<vector<bool>>(n+1, vector<bool>(m+1));
    adj = vector<vector<vector<pair<int,int>>>>(n+1, vector<vector<pair<int,int>>>(m+1));

    vector<vector<int>>a(n, vector<int>(m));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            cin >> a[i][j];
        }
    }
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            vector<pair<int,int>>neigh;
            if(i > 0)neigh.pb({i-1, j});
            if(i < n-1)neigh.pb({i+1, j});
            if(j > 0)neigh.pb({i, j-1});
            if(j < m-1)neigh.pb({i, j+1});
            for(auto v : neigh){
                if(a[v.first][v.second] != a[i][j]){
                    adj[i][j].pb(v);
                }
            }
        }
    }
    int c = 0;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(!visited[i][j]){
                dfs(i,j,c);
                c++;
            }
        }
    }
    while(q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << (color[a-1][b-1]==color[c-1][d-1]) << endl;
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