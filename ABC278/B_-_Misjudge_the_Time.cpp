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


int val(string a, string b){
    int c = stoi(a);
    int d = stoi(b);
    dbg(c,d);
    if(c < 24 && d < 60)return 1;
    return 0;
}
void solve()
{
    int h,m;
    cin >> h >> m;
    for(int i = h;i<=23;++i){
        int start = 0;
        if(i==h)start= m;
        for(int j = start;j<=59;++j){
            string s,t;
            stringstream ss,sss;
            ss << i;
            ss >> s;

            sss << j;
            sss >> t;
            if(s.size() == 1)s = "0"+s;
            if(t.size() == 1)t = "0"+t;
            swap(s[1],t[0]);
            if(val(s,t)){
                cout <<i << ' ' << j << endl;
                return;
            }
        }
    }
    for(int i = 0;i<=23;++i){
        for(int j = 0;j<=59;++j){
            string s,t;
            stringstream ss,sss;
            ss << i;
            ss >> s;

            sss << j;
            sss >> t;
            if(s.size() == 1)s = "0"+s;
            if(t.size() == 1)t = "0"+t;
            swap(s[1],t[0]);
            if(val(s,t)){
                cout <<i << ' ' << j << endl;
                return;
            }
        }
    }
    // if(h.size() == 1)h = "0" + h;
    // if(m.size() == 1)m = "0"+m;
    // dbg(h,m);
    // swap(h[1],m[0]);
    // dbg(h,m);
    // dbg(val(h,m));
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}