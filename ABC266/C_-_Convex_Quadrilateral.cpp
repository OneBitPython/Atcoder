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
    vector<pair<int,int>>a(4);
    for(int i = 0;i<4;++i)cin >> a[i].first >> a[i].second;
    bool ok = 1;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 1;i<4;++i){
        if(a[i].first < a[0].first)cnt0++;
        if(a[i].first > a[0].first)cnt1++;
    }
    if(cnt0 == 0 || cnt1 == 0)cout << "Yes";
    else cout << "No";
    // for(int i = 0;i<4;++i){
    //     for(int j = 0;j<4;++j){
    //         for(int k = 0;k<4;++k){
    //             if(i == j || j == k || i == k)continue;
    //             // a = (p1.x - p2.x, p1.y - p2.y)
    //             //b = (p1.x - p3.x, p1.y - p3.y)
    //             double c = a[i].first - 
    //         }
    //     }
    // }
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