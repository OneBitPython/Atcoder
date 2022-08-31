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
    int n,k;
    cin >> n >> k;
    vector<vector<int>>a(n,vector<int>(3));
    for(int i = 0;i<n;++i)cin >> a[i][0] >> a[i][1] >> a[i][2];
    vector<int>al,b;
    vector<int>together;
    for(int i = 0;i<n;++i){
        if(a[i][1] && !a[i][2])al.pb(a[i][0]);
        if(a[i][2] && !a[i][1])b.pb(a[i][0]);
        if(a[i][1] && a[i][2])together.pb(a[i][0]);
    }
    sort(all(al));
    sort(all(b));
    vector<int>p1(al.size()), p2(b.size());
    if(!al.empty())p1[0] = al[0];
    if(!b.empty())p2[0] = b[0];
    for(int i = 1;i<al.size();++i){
        p1[i] = p1[i-1]+al[i];
    }
    sort(all(together));
    for(int i = 1;i<b.size();++i)p2[i] = p2[i-1]+b[i];
    int res = 1e18;
    int sum = 0;

    for(int i = 0;i<together.size();++i){
        sum+=together[i];
        int cost = sum;
        int rem = k-(i+1);
        if(rem < 0)continue;
        if(rem == 0){
            res = min(res, cost);
            continue;
        }
        if(al.size() >= rem && b.size() >= rem){
            cost+=(p1[rem-1]);
            cost+=(p2[rem-1]);
            res = min(res, cost);
        }
    }
    int cost = 0;
    int rem = k;
    if (al.size() >= rem && b.size() >= rem)
    {
        cost += (p1[rem - 1]);
        cost += (p2[rem - 1]);
        res = min(res, cost);
    }
    if(res == 1e18)res = -1;
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