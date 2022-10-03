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

int lis(vector<int>&a){
    vector<int>l;
    for(int i = 0;i<(int)(a.size());++i){
        auto pos = lower_bound(all(l),a[i]);
        if(pos==l.end())l.pb(a[i]);
        else *pos = a[i];
    }
    return l.size();
}

int f(vector<pair<int,int>>a,vector<pair<int,int>>b){
    sort(all(a));
    vector<int>nb,na;
    int n = a.size();
    for(int i = 0;i<n;++i)nb.pb(b[a[i].second].first);
    for(int i = 0;i<n;++i)na.pb(a[i].first);
    int res1 = lis(na)+lis(nb);
    return res1;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>>a(n), b(n);
    for(int i = 0;i<n;++i){
        cin >>a[i].first;
        a[i].second = i;
    }
    for(int i = 0;i<n;++i){
        cin >>b[i].first;
        b[i].second = i;
    }
    cout << max(f(a,b),f(b,a)) << endl;
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