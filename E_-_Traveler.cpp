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
    vector<vector<int>>a(n+1);
    int mx = 0;
    vector<int>order;
    for(int i = 0;i<n;++i){
        int x,c;
        cin >> x >> c;
        a[c].pb(x);
        mx = max(mx, c);
        order.pb(c);
    }
    for(int i = 1;i<=n;++i){
        vector<int>g = a[i];
        sort(all(g));
        a[i] = g;
    }
    sort(all(order));
    order.insert(order.begin(), 0ll);
    vector<int>ne = {0};
    for(int i = 1;i<order.size();++i){
        if(order[i] == order[i-1])continue;
        ne.pb(order[i]);
    }
    a[0].pb(0);
    map<int,int>cost;
    cost[0] = 0;
    for(int i = 1;i<(int)(ne.size());++i){
        int x = a[ne[i]].front();
        int left = lower_bound(all(a[ne[i-1]]), x)-a[ne[i-1]].begin() - 1;
        int right = upper_bound(all(a[ne[i-1]]), x) - a[ne[i-1]].begin();
        vector<int>b;
        if(left>=0)b.pb(a[ne[i-1]][left]);
        if(right < a[ne[i-1]].size())b.pb(a[ne[i-1]][right]);

        x = a[ne[i]].back();
        left = lower_bound(all(a[ne[i-1]]), x)-a[ne[i-1]].begin() - 1;
        right = upper_bound(all(a[ne[i-1]]), x) - a[ne[i-1]].begin();
        if(left>=0)b.pb(a[ne[i-1]][left]);
        if(right < a[ne[i-1]].size())b.pb(a[ne[i-1]][right]);

        for(auto x : a[ne[i]]){
            int res = 1e18;
            for(auto y : b){
                int c = abs(y-a[ne[i]].front()) + (abs(a[ne[i]].front()-a[ne[i]].back())) + abs(a[ne[i]].back() - x);
                int c2 = abs(y-a[ne[i]].back()) + abs(a[ne[i]].back()-a[ne[i]].front()) + abs(a[ne[i]].front() - x);
                res = min(res, min(c,c2)+cost[y]);
            }
            cost[x] = res;
        }
    }
    int res = 1e18;
    for(auto x : a[mx]){
        res = min(res, abs(x)+cost[x]);
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