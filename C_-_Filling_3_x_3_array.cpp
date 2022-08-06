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
    int h1,h2,h3,w1,w2,w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    multiset<vector<int>>res;
    for(int a = 1;a<=30;++a){
        for(int b = 1;b<=30;++b){
            
            for(int d = 1;d<=30;++d){
                for(int e = 1;e<=30;++e){
                    // a,b,c
                    // d,e,f
                    // g,h,i
                    int c = h1-(a+b);
                    int f = h2-(d+e);
                    int g = w1-(a+d);
                    int h = w2 - (b+e);
                    int i = w3-(c+f);
                    vector<int>m = {a,b,c,d,e,f,g,h,i};
                    bool ok = 1;
                    for(auto x : m)ok&=(x>0);
                    if(ok && (a+b+c==h1)&&(d+e+f==h2)&&(g+h+i==h3)&&(a+d+g==w1)&&(b+e+h==w2)&&(c+f+i==w3))res.insert(m);
                }
            }
        }
    }
    cout << res.size() << endl;
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