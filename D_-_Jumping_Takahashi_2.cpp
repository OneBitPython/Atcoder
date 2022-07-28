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

int n;
vector<vector<int>>a;
vector<vector<pair<int,int>>>adj;

vector<int> dij(int u){
    vector<int>dist(n, 1e15);
    dist[u] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, u});
    vector<bool>visited(n);
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(auto v : adj[u]){
            if(visited[v.second])continue;
            int curr_dist = dist[v.second];
            int new_dist = max(dist[u], v.first);
            if(new_dist < curr_dist){
                dist[v.second] = new_dist;
                pq.push({new_dist, v.second});
            }
        }
    }
    return dist;
}
void solve()
{
    cin >> n;
    a = vector<vector<int>>(n, vector<int>(3));
    adj.resize(n);
    for(int i = 0;i<n;++i)cin >> a[i][0] >> a[i][1] >> a[i][2];
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            if(i == j)continue;
            int dist = abs(a[i][0] - a[j][0])+abs(a[i][1] - a[j][1]);
            // a[i][2] * s >= dist
            // s = ceil(dist/a[i][2]);
            int s = dist/a[i][2] + (dist%a[i][2]==0?0:1);
            adj[i].pb({s, j});
        }
    }
    int res = 1e18;
    for(int i = 0;i<n;++i){
        vector<int>cost = dij(i);
        int c = *max_element(all(cost));
        res = min(res, c);
    }
    cout << res << endl;
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