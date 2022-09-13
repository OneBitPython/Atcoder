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
    int n;
    cin >> n;
    map<int,int>idx;
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        idx[v] = i;
    }
    vector<vector<int>>dc;
    map<int,set<int>>pres;
    for(int i = 0;i<n;++i){
        vector<int>dist;
        int pos = idx[i];
        int d = 0;
        if(i >= pos)d = i-pos;
        else d = ((i+(n-pos)));
        dist.pb(d);
        if(d==0)dist.pb(n-1);
        else dist.pb(d-1);
        dist.pb((d+1)%n);
        dc.pb(dist);
    }
    for(int i = 0;i<n;++i){
        for(auto x : dc[i])pres[x].insert(i);
    }
    int res = 0;
    for(auto x: pres){
        res = max(res, (int)x.second.size());
    }
    cout << res;
    // map<int,int>cnt;
    // for(auto x: dist)cnt[x]++;
    
    // int res = 0;
    // for(int i = 0;i<n;++i){
    //     res = max(res, cnt[dist[i]]+cnt[dist[i]+1]+cnt[dist[i]+2]);
    // }
    // cout << res;
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