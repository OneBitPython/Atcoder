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


void solve()
{
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    vector<vector<int>>a(n, vector<int>(3));
    for(int i = 0;i<n;++i){
        cin >> a[i][0];
        a[i][2] = i;
    }

    for(int i = 0;i<n;++i)cin >> a[i][1];
    vector<int>res;
    sort(all(a), [&](auto one, auto two){
        if(one[0] == two[0])return one[2] < two[2];
        return one[0] > two[0];
    });
    for(int i = 0;i<x;++i){
        res.pb(a[i][2]);
    }
    vector<vector<int>>b;
    for(int i = x;i<a.size();++i)b.pb(a[i]);

    sort(all(b), [&](auto one, auto two){
        if(one[1] == two[1])return one[2] < two[2];
        return one[1] > two[1];
    });

    for(int i = 0;i<y;++i)res.pb(b[i][2]);
    vector<vector<int>>c;
    for(int i = y;i<b.size();++i)c.pb(b[i]);

    sort(all(c), [&](auto one, auto two){
        int s1 = one[0] + one[1];
        int s2 = two[0] + two[1];
        if(s1 == s2)return one[2] < two[2];
        return s1 > s2;
    });

    for(int i = 0;i<z;++i)res.pb(c[i][2]);
    sort(all(res));
    for(auto x : res)cout << x+1 << endl;
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