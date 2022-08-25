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
    // note : it's never optimal to go counjter-clock-counter. It's always optimal to go either counter-clock or clock-counter

    int n,c;
    cin >> n >> c;
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;++i)cin >> a[i].first >> a[i].second;
    vector<int>counter; // cost if you go counter clockwise from 0
    int sum = 0;
    for(int i = n-1;i>=0;--i){
        sum+=a[i].second;
        counter.pb(sum-(c-a[i].first));
    }
    sum = 0;
    vector<int>clock; // cost if you go clockwise starting from 0
    for(int i = 0;i<n;++i){
        sum+=a[i].second;
        clock.pb(sum-a[i].first);
    }
    vector<int>prefcounter(n), prefclock(n);
    prefcounter[0] = counter[0];
    prefclock[0] = clock[0];
    for(int i = 1;i<n;++i){
        prefcounter[i] = max(prefcounter[i-1], counter[i]);
        prefclock[i] = max(clock[i], prefclock[i-1]);
    }
    int res = 0;
    for(int i = 0;i<n;++i){
        // you are moving clockwise then anti clockwise
        // clock[i] + prefanti[n-i-2]
        res = max(res, clock[i]);
        if((n-i-2)>=0)res = max(res, clock[i] + prefcounter[n-i-2] - a[i].first);
    }
    for(int i = 0;i<n;++i){
        // you are moving anticlockwise then clockwise
        res = max(res, counter[i]);
        if((n-i-2)>=0)res = max(res, counter[i] + prefclock[n-i-2] - (c-a[n-i-1].first));
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