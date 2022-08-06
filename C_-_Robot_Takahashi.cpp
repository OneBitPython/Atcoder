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

string s;
int n;

void solve()
{
    cin >> n;
    string s;
    cin >> s;
    vector<double>a, k;
    for(int i = 0;i<n;++i){
        double v;
        cin >> v;
        if(s[i] == '0')k.pb(v);
        else a.pb(v);
    
    }
    sort(all(a));
    sort(all(k));
    int res = 0;
    dbg(a,k);
    for(auto x : a){
        // chose x as your value
        int idx = lower_bound(all(a), x) -  a.begin();
        int cnt = a.size()-idx;
        idx = lower_bound(all(k), x) - k.begin() - 1;
        cnt+=(idx+1);
        dbg(cnt, x,idx+1);
        res = max(res, cnt);
    }
    for(auto x : a){
        // chose x as your value
        double v = x+0.5;
        int idx = lower_bound(all(a), v) -  a.begin();
        int cnt = a.size()-idx;
        dbg(v, cnt);
        idx = lower_bound(all(k), v) - k.begin() - 1;
        cnt+=(idx+1);
        dbg(v ,cnt);
        res = max(res, cnt);
    }
    for(auto x : k){
        // chose x as your value
        int idx = lower_bound(all(k), x) - k.begin() - 1;
        int cnt = idx+1;
        idx = lower_bound(all(a), x) - a.begin();
        cnt+=(a.size()-idx);
        res = max(res, cnt);
    }
    for(auto x : k){
        // chose x as your value
        double v = x+0.5;
        int idx = lower_bound(all(k), v) - k.begin() - 1;
        int cnt = idx + 1;
        idx = lower_bound(all(a), v) - a.begin();
        cnt += (a.size() - idx);
        res = max(res, cnt);
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