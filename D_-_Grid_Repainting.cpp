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


void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<bool>>a(n, vector<bool>(m));
    int white = 0;
    for(int i = 0;i<n;++i){
        string s;
        cin >> s;
        for(int j = 0;j<m;++j){
            if(s[j] == '.')a[i][j] = 1;
            white+=a[i][j];
        }
    }
    vector<vector<int>>dist(n, vector<int>(m, 1e18));
    if(a[0][0])dist[0][0] = 1;
    vector<vector<bool>>visited(n, vector<bool>(m));
    queue<pair<int,int>>q;
    q.push({0, 0});
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        vector<pair<int,int>>neighbours;
        
        if(!a[i][j] || visited[i][j])continue;
        visited[i][j] = 1;

        if(i > 0)neighbours.pb({i-1, j});
        if(i < n-1)neighbours.pb({i+1, j});
        if(j > 0)neighbours.pb({i, j-1});
        if(j < m-1)neighbours.pb({i, j+1});
        for(auto v : neighbours){
            if(a[v.first][v.second]) dist[v.first][v.second] = min(dist[v.first][v.second], dist[i][j]+1);

            if(visited[v.first][v.second])continue;
            q.push(v);
        }
    }
    // dbg(dist);
    int res = white - dist[n-1][m-1];
    if(res < 0)res = -1;
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